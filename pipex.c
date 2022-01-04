/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmohamm <brmohamm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 17:21:06 by brmohamm          #+#    #+#             */
/*   Updated: 2022/01/04 23:50:47 by brmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int i;

void	path_finder(char **path,char **c,char **envp)
{
	int		i;
	int		if_access;
	char **paths02;
	char **paths03;
	
	if_access = -1;
	i = 0;
	while(envp[i] && *path == NULL)
	{
		*path= ft_strnstr(envp[i],"PATH=",5);
		i++;
	}
	paths02 = ft_split(*path,':');
	i = 0;
	while(paths02[i])
		i++;
	paths03 = (char **)malloc(sizeof(char *) * (i));
	paths03[i - 1] = NULL;
	i = 0;
	while (paths02[i])
	{
		paths03[i] = ft_strjoin(paths02[i],"/");
		i++;
	}
	i = 0;
	while (paths03[i] &&  if_access == -1)
	{
		*path = ft_strjoin(paths03[i],c[0]);
		if_access = access(*path,F_OK);
		if(if_access == -1)
			free(*path);
		i++;
	}
	free(paths02);
	free(paths03);
}

int **count(char **argv)
{
	int t;
	int **fd;

	t = 0;
	while (argv[i] != NULL)
		i = i  + 1;
	i -= 3 ; 
	fd = (int **)malloc(sizeof(int *) * (i + 1));
	fd[i] = NULL;
	if (!fd)
		return (0);
	while(t < i)
	{
		fd[t] = (int *)malloc(sizeof(int) * 2 + 1);
		if (!fd[t])
			return (0);
		fd[t][2] = '\0';
		t++;
	}
	t = 0;
	while (t < i)
	{
		pipe(fd[t]);
		t++;
	}
	return (fd);
}

void condetion(int t,char **argv,int **fd,char **envp)
{
	int id;
	char *path;
	char **c;

	path = NULL;
	id = fork();
	c = ft_split(argv[t + 2],' ');
	path_finder(&path,c,envp);
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
	free(c);
}
/* $> ./pipex here_doc LIMITER cmd cmd1 file */
/* cmd << LIMITER | cmd1 >> file */

/*./pipex file1 cmd1 cmd2 file2*/

void heredoc(char *argv)
{
    char r[10240];
    int error;
    char *input;

    input = malloc(1);
    input[0] = '\0';
    while(ft_strcmp(argv,r) != -10)
    { 
        input = ft_strjoin(input,r);
        write(1,"heredoc> ",9);
        error = read(0,r,50);
        r[error] = '\0';
    }
}

int main(int argc, char *argv[], char **envp)
{
	
	int **fd;
	int t;
	//(void)argc;
	//fd[0]read;
	//fd[1]write;
	//0 strin read
	//1 strout write
	fd = count(argv);
	t = 0;
	//open_file(argv[1]);
	printf("%d\n",ft_strcmp(argv[1],"here_doc"));
	if(ft_strcmp(argv[1],"here_doc") == 0)
	{
		heredoc(argv[2]);
		t = 1;
	}
	if(argc > 4 && ft_strcmp(argv[1],"here_doc") == 0)
	{
		
		while(t < i)
		{
			condetion(t,argv,fd,envp);
			waitpid(0, NULL,0);
			close(fd[t][1]);
			dup2(fd[t][0],0);
			close(fd[t][0]);
			t++;
		}
		free(fd);
	}
	
	return (0);
}