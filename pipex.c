/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmohamm <brmohamm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 17:21:06 by brmohamm          #+#    #+#             */
/*   Updated: 2022/01/31 19:33:28 by brmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	g_i;
int	g_fals;
int	g_t;

void	continue_of_condetion(char **c, char **argv, char *path, char **envp)
{
	int		v ;

	v = -1;
	if (g_t == g_i - 1)
	{
		if (g_fals == 0)
			creat_fille(argv[g_i + 3]);
		else
			creat_fille(argv[g_i + 2]);
		if (execve(path, &c[0], envp) == -1)
		{
			perror(c[0]);
			while (g_t > 1 && v == -1)
			{
				g_t--;
				c = ft_split(argv[g_t + 2], ' ');
				path = NULL;
				path_finder(&path, c, envp);
				v = execve(path, &c[0], envp);
			}
		}
	}
}

void	condetion(char **argv, int **fd, char **envp)
{
	int		id;
	char	*path;
	char	**c;

	path = NULL;
	id = fork();
	if (g_fals == 0)
		c = ft_split(argv[g_t + 3], ' ');
	else
		c = ft_split(argv[g_t + 2], ' ');
	path_finder(&path, c, envp);
	if (id == 0)
	{
		if (g_t < g_i - 1)
		{
			close(fd[g_t][0]);
			dup2(fd[g_t][1], 1);
			close(fd[g_t][1]);
			if (execve(path, &c[0], envp) == -1)
				perror(c[0]);
		}
		continue_of_condetion(c, argv, path, envp);
	}
	free(c);
}
/* $> ./pipex here_doc LIMITER cmd cmd1 file */
/* cmd << LIMITER | cmd1 >> file */

/*./pipex file1 cmd1 cmd2 file2*/
/*
	fd[0]read;
	fd[1]write;
	0 strin read
	1 strout write
*/

int	main(int argc, char *argv[], char **envp)
{
	int	**fd;
	int	x;
	int	y;

	g_fals = 1;
	g_t = 0;
	if (ft_strcmp(argv[1], "here_doc") == 0)
	{
		heredoc(argv[2]);
		g_fals = 0;
	}
	fd = count(argv, &g_i, g_fals);
	if (argc > 4)
	{
		if (open_file(argv[1]) == -1)
		{
			perror(argv[1]);
			if (g_fals == 0)
				creat_fille(argv[g_i + 3]);
			else
				creat_fille(argv[g_i + 2]);
			exit(0);
		}
		x = g_t;
		y = g_i;
		while (g_t < g_i)
		{
			condetion(argv, fd, envp);
			close(fd[g_t][1]);
			dup2(fd[g_t][0], 0);
			close(fd[g_t][0]);
			g_t++;
		}
		while (x < y)
		{
			wait(NULL);
			x++;
		}
		free(fd);
	}
	else
		perror("few args");
	if (g_fals == 0)
		unlink(argv[1]);
	return (0);
}
