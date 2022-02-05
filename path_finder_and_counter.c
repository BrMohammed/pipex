/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finder_and_counter.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmohamm <brmohamm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 17:47:53 by brmohamm          #+#    #+#             */
/*   Updated: 2022/02/05 19:51:18 by brmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**path_finder_half(char **path, char **paths02, char **envp)
{
	int		i;
	char	**paths03;

	i = 0;
	while (envp[i] && *path == NULL)
	{
		*path = ft_strnstr(envp[i], "PATH=", 5);
		i++;
	}
	paths02 = ft_split(*path, ':');
	i = 0;
	while (paths02[i])
		i++;
	paths03 = (char **)malloc(sizeof(char *) * (i + 1));
	paths03[i] = NULL;
	i = 0;
	while (paths02[i])
	{
		paths03[i] = ft_strjoin(paths02[i], "/");
		i++;
	}
	return (paths03);
}

void	path_finder(char **path, char **c, char **envp)
{
	int		i;
	int		if_access;
	char	**paths02;
	char	**paths03;

	if_access = -1;
	paths02 = NULL;
	paths03 = path_finder_half(path, paths02, envp);
	i = 0;
	while (paths03[i] && if_access == -1)
	{
		*path = ft_strjoin(paths03[i], c[0]);
		if_access = access(*path, F_OK);
		if (if_access == -1)
			free(*path);
		i++;
	}
	free(paths02);
	free(paths03);
}

void	count_continue(char **argv, int fals, int *i)
{
	while (argv[*i] != NULL)
		*i = *i + 1;
	if (fals == 0)
		*i = *i - 4;
	else
		*i = *i - 3 ;
}

int	**count(char **argv, int *i, int fals)
{
	int	t;
	int	**fd;

	t = 0;
	count_continue(argv, fals, i);
	fd = (int **)malloc(sizeof(int *) * (*i + 1));
	fd[*i] = NULL;
	if (!fd)
		return (0);
	while (t < *i)
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

void	close_childe(int g_t, int **fd,int index)
{
	int t = 0;
	int v = 0;
	while (fd[v])
	{
		while (fd[v][t])
		{
			if (g_t != v || t != index)
				close(fd[v][t]);
			t++;
		}
		v++;
	}
}
