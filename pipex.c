#include "pipex.h"

int main(int argc, char *argv[], char **envp)
{
    int i;
    char *path;
    int if_access;

    if_access = -1;
    i = 0;
    char *paths[] = {"/usr/local/bin/" ,"/usr/bin/","/bin/","/usr/sbin/","/sbin/","/usr/local/munki/"};
    if(argc == 2)
    {
        while (i != 6 &&  if_access == -1)
        {
        
            path = ft_strjoin(paths[i],argv[1]);
            if_access = access(path,F_OK);
            if(if_access == -1)
            free(path);
            i++;
        }
        if (execve(path,&argv[1],envp) == -1)
            perror("Could not execve");
    }
    
    return (0);
}