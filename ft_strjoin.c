/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmohamm <brmohamm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 17:19:31 by brmohamm          #+#    #+#             */
/*   Updated: 2022/02/06 22:58:15 by brmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*loop_full_c(char const *s1, char const *s2, char *c)
{
	int	ls1;
	int	ls2;
	int	n;

	ls1 = 0;
	ls2 = 0;
	n = 0;
	while (s1[ls1] != '\0')
	{
		c[n] = s1[ls1];
		ls1++;
		n++;
	}
	while (s2[ls2] != '\0')
	{
		c[n] = s2[ls2];
		ls2++;
		n++;
	}
	c[n] = '\0';
	return (c);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		ls1;
	int		ls2;
	char	*c;

	ls1 = 0;
	ls2 = 0;
	if (!s1 || !s2)
		return (NULL);
	while (s1[ls1] != '\0')
		ls1++;
	while (s2[ls2] != '\0')
		ls2++;
	c = malloc(sizeof(char) * (ls1 + ls2 + 1));
	if (c == 0)
		return (NULL);
	loop_full_c (s1, s2, c);
	free((char *)s1);
	return (c);
}
