/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmohamm <brmohamm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 17:19:42 by brmohamm          #+#    #+#             */
/*   Updated: 2022/02/06 23:04:51 by brmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include <errno.h>
# include <sys/wait.h>

char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
void	creat_fille(char *argv);
void	open_file(char **argv, int last);
char	*ft_strnstr(const char *str, const char *find, size_t slen);
int		ft_strcmp( const char *s1, const char *s2);
void	path_finder(char **path, char **c, char **envp);
int		**count(char **argv, int *i, int fals);
void	heredoc(char *argv);
void	close_childe(int g_t, int **fd, int index);ß
typedef struct s_data
{
	int		i;
	int		fals;
	in		t;
	char	**env;
}t_data;

#endif