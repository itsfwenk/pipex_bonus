/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 14:45:41 by fli               #+#    #+#             */
/*   Updated: 2024/06/25 17:10:48 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/pipex.h"
#include "libft.h"

int	cmd1_child(t_pids	**pid_list, int pipefd[2], char **argv, char **envp)
{
	int		fd_in;
	pid_t	pid1;
	t_pids	*new_nod;

	pid1 = fork();
	if (pid1 == 0)
	{
		fd_in = open(argv[1], O_RDONLY);
		if (fd_in == -1)
		{
			infile_check(argv, errno);
			return (-10);
		}
		if (dup2(fd_in, 0) == -1)
			return (-1);
		close(fd_in);
		if (dup2(pipefd[1], 1) == -1)
			return (-1);
		close_pipe(pipefd);
		if (cmd1_exec(argv, envp) == -1)
			return (-1);
	}
	new_nod = ft_lstnew_pipex(pid1);
	if (new_nod == NULL)
	{
		ft_lstclear_pipex(pid_list);
		return (-1);
	}
	ft_lstadd_back_pipex(pid_list, new_nod);
	//waitpid(pid1, &(new_nod->status), 0);
	return (new_nod->status);
}

int	cmd2_child(t_pids	**pid_list, int pipefd[2], char **argv, char **envp)
{
	int		fd_out;
	pid_t	pid2;
	t_pids	*new_nod;

	pid2 = fork();
	if (pid2 == 0)
	{
		fd_out = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (fd_out == -1)
		{
			ft_fprintf(2, "%s: Permission denied", argv[4]);
			return (-1);
		}
		if (dup2(fd_out, 1) == -1)
			return (-1);
		close(fd_out);
		if (dup2(pipefd[0], 0) == -1)
			return (-1);
		close_pipe(pipefd);
		if (cmd2_exec(argv, envp) == -1)
			return (-1);
	}
	new_nod = ft_lstnew_pipex(pid2);
	if (new_nod == NULL)
	{
		ft_lstclear_pipex(pid_list);
		return (0);
	}
	ft_lstadd_back_pipex(pid_list, new_nod);
	// close_pipe(pipefd);
	// waitpid(pid2, &child2_status, 0);
	return (new_nod->status);
}

int	main(int argc, char **argv, char **envp)
{
	t_pids	*pid_list;
	int	pipefd[2];

	if (argc != 5)
		return (0);
	if (pipe(pipefd) == -1)
	{
		ft_fprintf(2, "pipe error");
		exit(EXIT_FAILURE);
	}
	pid_list = NULL;
	if (cmd1_child(&pid_list, pipefd, argv, envp) == -10)
		exit(EXIT_FAILURE);
	if (cmd2_child(&pid_list, pipefd, argv, envp) == -1)
		exit(EXIT_FAILURE);
	close_pipe(pipefd);
	wait_pids(&pid_list);
	ft_lstclear_pipex(&pid_list);
}

// test for get_path
	// if (argc >= 50)
	// 	return (0);
	// printf("%s\n", argv[0]);
	// char **path = get_path(envp);
	// int i = 0;
	// while (path[i])
	// 	printf("%s\n", path[i++]);
