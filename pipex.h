/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmohamm <brmohamm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 17:19:42 by brmohamm          #+#    #+#             */
/*   Updated: 2022/01/31 19:34:47 by brmohamm         ###   ########.fr       */
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
int		open_file(char *argv);
char	*ft_strnstr(const char *str, const char *find, size_t slen);
int		ft_strcmp( const char *s1, const char *s2);
void	path_finder(char **path, char **c, char **envp);
int		**count(char **argv, int *i, int fals);
void	heredoc(char *argv);

#endif