/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmohamm <brmohamm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 17:19:21 by brmohamm          #+#    #+#             */
/*   Updated: 2022/02/06 14:37:03 by brmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	creat_fille(char *argv)
{
	int	output;

	output = open(argv, O_RDWR | O_CREAT | O_TRUNC, 0644);
	dup2(output, 1);
	close(output);
}

int	open_file(char *argv)
{
	int	input;

	input = open(argv, O_RDONLY);
	dup2(input, 0);
	close(input);
	return (input);
}
