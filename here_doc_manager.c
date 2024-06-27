/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_manager.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 10:25:55 by fli               #+#    #+#             */
/*   Updated: 2024/06/27 12:29:50 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/pipex.h"

// void	here_doc_checker(char **argv, int *cmd_i)
// {
// 	if (argv[1] == "here_doc")
// 	{
// 		cmd_i = 3;
// 	}
// 	else
// 	{
// 		cmd_i = 2;
// 	}
// }

int	if_here_doc(int argc, char **argv)
{
	int	fd_hd;
	char	*next_line;

	fd_hd = open("here_doc", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd_hd == -1)
		return (-1);
	next_line = get_next_line(0);
	dprintf(2,"next_line is %s", next_line);
	while (ft_strncmp(next_line, argv[2], ft_strlen(argv[2])) != 0)
	{
		write(fd_hd, next_line, ft_strlen(next_line));
		free(next_line);
		next_line = get_next_line(0);
		dprintf(2,"next_line is %s", next_line);
	}
	free(next_line);
	char file[1000000];
	int read_return = read(fd_hd, file, 99999);
	file[read_return] = '\0';
	dprintf(2, "in here doc file :\n %s", file);
	return (0);
}

int	main(int argc, char **argv)
{
	int use = argc + 1;
	dprintf(2,"argv 2 is %s", argv[2]);
	if_here_doc(argc, argv);
}
