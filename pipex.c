#include "pipex.h"

void creat_fille(char *argv)
{
    int output;

    output = open(argv,O_RDWR | O_CREAT,0777);
    dup2(output,1);
    close(output);
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
int **count(int *i,char **argv)
{
    int t;
    int **fd;

    t = 0;
    while (argv[*i] != NULL)
        i++;
    *i -= 3 ; 
    fd = (int **)malloc(sizeof(int *) * (*i + 1));
    fd[*i] = NULL;
	if (!fd)
		return (0);
    while(t < *i)
    {
        fd[t] = (int *)malloc(sizeof(int) * 2 + 1);
        if (!fd[t])
		    return (0);
        fd[t][2] = '\0';
        t++;
    }
    t = 0;
    while (t < *i)
    {
        pipe(fd[t]);
        t++;
    }
    return (fd);
}

int main(int argc, char *argv[], char **envp)
{
    char *path;
    (void)argc;
    char **c;
    int id;
    int i;
    int **fd;
    int t;
    //fd[0]read;
    //fd[1]write;
    //0 strin read
    //1 strout write 
    
    i = 0;
    fd = count(&i,argv);
    t = 0;
    open_file(argv[1]);
    while(t < i)
    {
        id = fork();
        c = ft_split(argv[t + 2],' ');
        path_finder(&path,c);
        if(id == 0)
        {
            if(t < i - 1)
            {
                close(fd[t][0]);
                dup2(fd[t][1],1);
                close(fd[t][1]);
                if (execve(path,&c[0],envp) == -1)
                    perror("Could not execve");
            }
            if(t == i - 1)
            {
                creat_fille(argv[i + 2]);
                if (execve(path,&c[0],envp) == -1)
                    perror("Could not execve");
            }
        }
        waitpid(id, NULL,0);
        free(c);
        close(fd[t][1]);
        dup2(fd[t][0],0);
        close(fd[t][0]);
        t++;
    }
    return (0);   
}