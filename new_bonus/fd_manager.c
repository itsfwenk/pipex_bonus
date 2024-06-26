/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_manager.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 10:16:14 by fli               #+#    #+#             */
/*   Updated: 2024/06/26 11:44:58 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	cmd1_fd_manager(char **argv, t_pids	*new_nod)
{
	int	fd_in;

	fd_in = open(argv[1], O_RDONLY);
	if (fd_in == -1)
	{
		infile_check(argv, errno);
		return (-10);
	}
	if (dup2(fd_in, 0) == -1)
		return (-1);
	close(fd_in);
	if (dup2((new_nod)->pipefd[1], 1) == -1)
		return (-1);
	close_pipe((new_nod)->pipefd);
}
int	cmd_fd_manager(t_pids	*child_nod)
{
	if (dup2((child_nod)->pipefd[1], 1) == -1)
		return (-1);
	close_pipe((child_nod)->pipefd);
}

int	cmd2_fd_manager(int cmd_i, char **argv, t_pids	*new_nod)
{
	int	fd_out;

	fd_out = open(argv[cmd_i], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd_out == -1)
	{
		ft_fprintf(2, "%s: Permission denied", argv[4]);
		return (-1);
	}
	if (dup2(fd_out, 1) == -1)
		return (-1);
	close(fd_out);
	if (dup2((new_nod)->pipefd[0], 0) == -1)
		return (-1);
	close_pipe((new_nod)->pipefd);
}
