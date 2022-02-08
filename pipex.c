/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmohamm <brmohamm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 17:21:06 by brmohamm          #+#    #+#             */
/*   Updated: 2022/02/08 02:53:55 by brmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	g_i;
int	g_fals;
int	g_t;
int	g_bad_file;

void	continue_of_condetion(char **c, char **argv, char *path, char **envp)
{
	int		v ;

	v = -1;
	if (g_t == g_i - 1)
	{
		creat_fille(argv[g_i + 2]);
		if (execve(path, &c[0], envp) == -1)
		{
			perror(c[0]);
			exit(127);
		}
	}
	exit(0);
}

void	condetion(char ***c, char **argv, int **fd, char **envp)
{
	int		id;
	char	*path;

	path = NULL;
	id = fork();
	*c = ft_split(argv[g_t + 2], ' ');
	path_finder(&path, *c, envp);
	if (id == 0)
	{
		if (g_t < g_i - 1)
		{
			close_childe(g_t, fd, 1);
			dup2(fd[g_t][1], 1);
			close(fd[g_t][1]);
			if (execve(path, c[0], envp) == -1)
			{
				perror(*c[0]);
			}
		}
		continue_of_condetion(*c, argv, path, envp);
	}
	if (path != NULL)
		free(path);
	close_childe(g_t, fd, 0);
	dup2(fd[g_t][0], 0);
}
/* $> ./pipex here_doc LIMITER cmd cmd1 file */
/* cmd << LIMITER | cmd1 >> file */
/*
	fd[0]read;
	fd[1]write;
	0 strin read
	1 strout write
*/

void	exicution(char **argv, int **fd, char **envp)
{
	int		x;
	int		y;
	char	**c;
	int		t;

	x = g_t;
	y = g_i;
	while (g_t < g_i)
	{
		t = 0;
		condetion(&c, argv, fd, envp);
		close(fd[g_t][1]);
		close(fd[g_t][0]);
		while (c[t])
			free(c[t++]);
		free(c);
		g_t++;
	}
	while (x < y)
	{
		wait(NULL);
		x++;
	}
}

int	main(int argc, char *argv[], char **envp)
{
	int	**fd;

	g_fals = 1;
	g_t = 0;
	g_bad_file = 0;
	if (argc == 5)
	{
		fd = count(argv, &g_i, g_fals);
		open_file(argv, &g_bad_file);
		exicution(argv, fd, envp);
	}
	else if (argc < 5)
		perror("few args");
	else
		perror("to many args");
	if (g_bad_file == 1)
		unlink(argv[1]);
	return (0);
}
