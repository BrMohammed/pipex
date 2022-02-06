/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmohamm <brmohamm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 17:19:21 by brmohamm          #+#    #+#             */
/*   Updated: 2022/02/06 18:00:45 by brmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	creat_fille(char *argv)
{
	int	output;

	output = open(argv, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if(output == -1)
	{
		perror(argv);
	}
	else
	{
		dup2(output, 1);
		close(output);
	}
	
}

void	open_file(char *argv)
{
	int	input;

	input = open(argv, O_RDONLY);
	if (input == -1)
	{
		perror(argv);
		// if (g_fals == 0)
		// 	creat_fille(argv[g_i + 3]);
		// else
		// 	creat_fille(argv[g_i + 2]);
			//exit(2);
	}
	else
	{
		dup2(input, 0);
		close(input);
	}
}

// int	open_file(char *argv)
// {
// 	int	input;

// 	input = open(&argv[1], O_RDONLY);
// 	dup2(input, 0);
// 	close(input);
// 	return (input);
// }
