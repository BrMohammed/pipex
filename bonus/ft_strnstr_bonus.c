/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmohamm <brmohamm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 17:19:35 by brmohamm          #+#    #+#             */
/*   Updated: 2022/02/07 19:20:53 by brmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	*ft_strnstr(const char *str, const char *find, size_t slen)
{
	size_t	n;
	size_t	k;

	k = 0;
	n = 0;
	if (find[k] == '\0')
		return ((char *)str);
	if (slen == 0)
		return (NULL);
	while (str[k] != '\0' && k <= slen)
	{
		if (find[n] == str[k])
		{
			while (str[k + n] == find[n] && find[n] != '\0')
				n++;
			if (find[n] == '\0' && (n + k) <= slen)
				return ((char *)&str[k + 5]);
		}
		n = 0;
		k++;
	}
	return (NULL);
}
