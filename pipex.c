#include "pipex.h"

int creat_fille(char *argv)
{
    int output;

    output = open(argv,O_RDWR | O_CREAT,0777);
    dup2(output,1);
    close(output);
    return(output);
}
void open_file(char *argv)
{
    int input;

    input =  open(argv,O_RDWR ,0777);
    if (input == -1)
        return;
    dup2(input,0);
    close(input);
}
void path_finder(char **path,char **c)
{
    int i;
    int if_access;

    if_access = -1;
    i = 0;
    char *paths[] = {"/usr/local/bin/" ,"/usr/bin/","/bin/","/usr/sbin/","/sbin/","/usr/local/munki/"};
    while (i != 6 &&  if_access == -1)
    {
        *path = ft_strjoin(paths[i],c[0]);
        if_access = access(*path,F_OK);
        if(if_access == -1)
        free(*path);
        i++;
    }
}

int main(int argc, char *argv[], char **envp)
{
    char *path;
    int fd[2][2];
    (void)argc;
    char **c;
    int id;
    //fd[0]read;
    //fd[1]write;
    //0 strin read
    //1 strout write
    pipe(fd[0]);
    pipe(fd[1]);
    int t = 0; 
    open_file(argv[1]);
    while(t < 2)
    {
        id = fork();
        c = ft_split(argv[t+2],' ');
        path_finder(&path,c);
        if(id == 0)
        {
            close(fd[t][0]);
            dup2(fd[t][1],1);
            close(fd[t][1]);
            if (execve(path,&c[0],envp) == -1)
            perror("Could not execve");
        }
        dup2(fd[t][0],0);
        waitpid(id, NULL,0);
        free(c);
        t++;
    }
    t--;
    creat_fille(argv[4]);
    write(1,&fd[t][1],sizeof(fd[t][1]));
    return (0);   
}