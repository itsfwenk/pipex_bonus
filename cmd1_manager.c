/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd1_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 10:56:56 by fli               #+#    #+#             */
/*   Updated: 2024/06/28 18:04:00 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/pipex.h"

int	cmd1_child(int *cmd_i, t_pids	**pid_list, char **argv, char **envp)
{
	pid_t	pid1;
	t_pids	*new_nod;

	new_nod = ft_lstnew_pipex((*cmd_i)++);
	if (new_nod == NULL)
		return (ft_lstclear_pipex(pid_list), -1);
	ft_lstadd_back_pipex(pid_list, new_nod);
	if (pipe((new_nod)->pipefd) == -1)
		exit(EXIT_FAILURE);
	pid1 = fork();
	if (pid1 == 0)
	{
		if (cmd1_fd_manager(argv, new_nod) == -10)
			return (-10);
		cmd1_exec(new_nod->cmd_i, new_nod, argv, envp);
	}
	// if (new_nod->exec == -1)
	// 	waitpid(new_nod->p_id, &(new_nod->status), 0);
	if (dup2(new_nod->pipefd[0], STDIN_FILENO) == -1)
		return (-1);
	close_pipe(new_nod->pipefd);
	new_nod->p_id = pid1;
	return (new_nod->status);
}

void	cmd1_exec(int cmd_i, t_pids	*new_nod, char **argv, char **envp)
{
	char	**cmd1;
	char	*cmd1_path;

	// if (here_doc_checker(argv) == -11)
	// 	cmd1 = ft_split((const char *)argv[2], ' ');
	// else
	// 	cmd1 = ft_split((const char *)argv[3], ' ');
	cmd1 = ft_split((const char *)argv[cmd_i], ' ');
	if (cmd1 == NULL)
		return ;
	cmd1_path = get_pathname(envp, cmd1[0]);
	if (cmd1_path == NULL)
	{
		free(cmd1);
		// ft_fprintf(2, "%s: command not found\n", argv[2]);
		// write(2, argv[2], ft_strlen(argv[2]));
		// write(2, ": command not found\n", ft_strlen(": command not found\n"));
		new_nod->exec = -1;
		exit(EXIT_FAILURE);
	}
	if (cmd_exec(cmd1, cmd1_path, envp) == -1)
	{
		free(cmd1);
		free(cmd1_path);
		exit(EXIT_FAILURE);
	}
	// return (0);
}
