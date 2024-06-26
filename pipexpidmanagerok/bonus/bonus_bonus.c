/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 12:56:52 by fli               #+#    #+#             */
/*   Updated: 2024/06/25 14:40:13 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/pipex.h"

int	cmd2_exec(int cmdn, char **argv, char **envp)
{
	char	**cmd2;
	char	*cmd2_path;

	cmd2 = ft_split((const char *)argv[cmdn], ' ');
	if (cmd2 == NULL)
		return (-1);
	cmd2_path = get_pathname(get_path_tab(envp), cmd2[0]);
	if (cmd2_path == NULL)
	{
		free(cmd2);
		ft_fprintf(2, "%s: command not found\n", argv[cmdn]);
		return (-1);
	}
	if (cmd_exec(cmd2, cmd2_path, envp) == -1)
	{
		free(cmd2);
		free(cmd2_path);
		return (-1);
	}
	return (0);
}

int	cmd2_child(int cmdn, int pipefd[2], char **argv, char **envp)
{
	int		fd_out;
	int		child2_status = 0;
	pid_t	pid2;

	dprintf(2, "IN LAST CMD %s, cmd : %s\n", __func__, argv[cmdn]);
	pid2 = fork();
	if (pid2 == 0)
	{
		fd_out = open(argv[cmdn + 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (fd_out == -1)
		{
			ft_fprintf(2, "%s: Permission denied", argv[cmdn + 1]);
			return (-1);
		}
		if (dup2(fd_out, 1) == -1)
			return (-1);
		close(fd_out);
		if (dup2(pipefd[0], 0) == -1)
			return (-1);
		close_pipe(pipefd);
		if (cmd2_exec(cmdn, argv, envp) == -1)
			return (-1);
	}
	close_pipe(pipefd);
	/*waitpid(pid2, &child2_status, 0);*/
	return (child2_status);
}

int	main(int argc, char **argv, char **envp)
{
	int	cmdn;
	int	pipe_ret;
	int	pipefd[2];

	if (argc < 5)
		return (0);
	pipe_ret = pipe(pipefd);
	if (pipe_ret == -1)
	{
		ft_fprintf(2, "pipe error");
		exit(EXIT_FAILURE);
	}
	if (cmd1_child(pipefd, argv, envp) == -10)
		exit(EXIT_FAILURE);
	print_content(pipefd[0]);
	cmdn = 3;
	while (cmdn < (argc - 2))
	{
		dprintf(2, "entering middle child\n");
		cmdn_child(cmdn, pipefd, argv, envp);
		print_content(pipefd[0]);
		cmdn++;
	}
	dprintf(2, "out of middle child\n");
	if (cmd2_child(cmdn, pipefd, argv, envp) == -1)
		exit(EXIT_FAILURE);
	print_content(pipefd[0]);
	wait(NULL);
}
