/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmohamm <brmohamm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 17:47:53 by brmohamm          #+#    #+#             */
/*   Updated: 2022/02/06 20:35:06 by brmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**path_finder_half(char **path, char **paths02, char **envp)
{
	int		i;
	char	**paths03;

	i = 0;
	while (envp[i] && *path == NULL)
		*path = ft_strnstr(envp[i++], "PATH=", 5);
	if (*path != NULL)
	{
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
	}
	else
		paths03 = NULL;
	return (paths03);
}
void link_ready()
{
	if (if_access == -1)
	{
		*path = ft_strjoin(c[0], "");
		if_access = access(*path, F_OK);
		if (if_access == -1)
			free(*path);
	}
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
	if (paths03 != NULL)
	{
		while (paths03[i] && if_access == -1)
		{
			*path = ft_strjoin(paths03[i], c[0]);
			if_access = access(*path, F_OK);
			if (if_access == -1)
				free(*path);
			i++;
		}
	}
	link_ready();
	free(paths02);
	free(paths03);
}

void	close_childe(int g_t, int **fd, int index)
{
	int	t;
	int	v;

	t = 0;
	v = 0;
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
