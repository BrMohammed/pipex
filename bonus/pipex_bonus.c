/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmohamm <brmohamm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 17:21:06 by brmohamm          #+#    #+#             */
/*   Updated: 2022/02/07 22:48:05 by brmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	continue_of_condetion(char **c, char **argv, char *path, t_data *data)
{
	int		v ;

	v = -1;
	if (data->t == data->i - 1)
	{
		if (data->fals == 0)
			creat_fille(argv[data->i + 3]);
		else
			creat_fille(argv[data->i + 2]);
		if (execve(path, &c[0], data->env) == -1)
		{
			perror(c[0]);
			exit(127);
		}
	}
	exit(0);
}

void	condetion(char ***c, char **argv, int **fd, t_data *data)
{
	int		id;
	char	*path;

	path = NULL;
	if (data->fals == 0)
		*c = ft_split(argv[data->t + 3], ' ');
	else
		*c = ft_split(argv[data->t + 2], ' ');
	path_finder(&path, *c, data->env);
	id = fork();
	if (id == 0)
	{
		if (data->t < data->i - 1)
		{
			close_childe(data->t, fd, 1);
			dup2(fd[data->t][1], 1);
			close(fd[data->t][1]);
			if (execve(path, c[0], data->env) == -1)
				perror(*c[0]);
		}
		continue_of_condetion(*c, argv, path, data);
	}
	if (path != NULL)
		free(path);
	dup2(fd[data->t][0], 0);
}

void	exicution(char **argv, int **fd, t_data *data)
{
	int		x;
	int		y;
	char	**c;
	int		t;

	x = data->t;
	y = data->i;
	while (data->t < data->i)
	{
		t = 0;
		condetion(&c, argv, fd, data);
		while (c[t])
			free(c[t++]);
		close(fd[data->t][0]);
		close(fd[data->t][1]);
		free(c);
		data->t++;
	}
	while (x < y)
	{
		wait(NULL);
		x++;
	}
}

int	main(int argc, char *argv[], char **envp)
{
	int		**fd;
	t_data	data;

	data.fals = 1;
	data.t = 0;
	data.i = 0;
	data.env = envp;
	if (ft_strcmp(argv[1], "here_doc") == 0)
	{
		heredoc(argv[2]);
		data.fals = 0;
	}
	if (argc > 4)
	{
		fd = count(argv, &data.i, data.fals);
		open_file(argv, data.i + 2);
		exicution(argv, fd, &data);
	}
	else
		perror("few args");
	if (data.fals == 0)
		unlink(argv[1]);
	return (0);
}
