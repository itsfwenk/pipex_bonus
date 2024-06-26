/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 14:45:41 by fli               #+#    #+#             */
/*   Updated: 2024/06/19 17:47:32 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft.h"

int	cmd1_child(int pipefd[2], char **argv, char **envp)
{
	int		fd_in;
	int		child1_status;
	pid_t	pid1;

	pid1 = fork();
	if (pid1 == 0)
	{
		fd_in = open(argv[1], O_RDONLY);
		if (fd_in == -1)
			return (-1);
		if (dup2(fd_in, 0) == -1)
			return (-1);
		close(fd_in);
		if (dup2(pipefd[1], 1) == -1)
			return (-1);
		close(pipefd[0]);
		close(pipefd[1]);
		if (cmd1_exec(argv, envp) == -1)
			return (-1);
	}
	waitpid(pid1, &child1_status, 0);
	return (child1_status);
}

int	cmd2_child(int pipefd[2], char **argv, char **envp)
{
	int		fd_out;
	int		child2_status;
	pid_t	pid2;

	pid2 = fork();
	if (pid2 == 0)
	{
		fd_out = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (fd_out == -1)
			return (-1);
		if (dup2(fd_out, 1) == -1)
			return (-1);
		close(fd_out);
		if (dup2(pipefd[0], 0) == -1)
			return (-1);
		close(pipefd[0]);
		close(pipefd[1]);
		if (cmd1_exec(argv, envp) == -1)
			return (-1);
	}
	waitpid(pid2, &child2_status, 0);
	return (child2_status);
}

int	main(int argc, char **argv, char **envp)
{
	printf("ok");
	int		pipefd[2];

	if (argc != 5)
		return (0);
	if (pipe(pipefd) == -1)
	{
		perror("pipe error");
		exit(EXIT_FAILURE);
	}
	if (cmd1_child(pipefd, argv, envp) == -1)
		exit(EXIT_FAILURE);
	if (cmd2_child(pipefd, argv, envp) == -1)
		exit(EXIT_FAILURE);
	close(pipefd[0]);
	close(pipefd[1]);
}

// test for get_path
	// if (argc >= 50)
	// 	return (0);
	// printf("%s\n", argv[0]);
	// char **path = get_path(envp);
	// int i = 0;
	// while (path[i])
	// 	printf("%s\n", path[i++]);
