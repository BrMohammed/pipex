#include "pipex.h"

void creat_fille(int *fd,char *argv)
{
    int output;

    output = open(argv,O_RDWR | O_CREAT,0777);
    close(fd[1]);
    dup2(fd[0],0);
    dup2(output,1);
    close(output);
    close(fd[0]);
}

void open_file(int *fd,char *argv)
{
    int input;

    input =  open(argv,O_RDWR ,0777);
    if (input == -1)
        return;
    close(fd[0]);
    dup2(input,0);
    dup2(fd[1],1);
    close(fd[1]);
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
    int fd[2];
    (void)argc;
    char **c;
    //fd[0]read;
    //fd[1]write;
    //0 strin read
    //1 strout write
    pipe(fd);
    c = ft_split(argv[2],' ');
    path_finder(&path,c);
    int id = fork();
    if(id == 0)
    {
        //child 
        open_file(fd,argv[1]);
        if (execve(path,&c[0],envp) == -1)
            perror("Could not execve");
    }
    waitpid(id , NULL,0);
    free(c);
    c = ft_split(argv[3],' ');
    path_finder(&path,c);
    if(id != 0)
    {
        //parent
        creat_fille(fd,argv[4]);
        if (execve(path,&c[0],envp) == -1)
            perror("Could not execve");
    }
    return (0);
}