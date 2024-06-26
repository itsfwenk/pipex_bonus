/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   middle_cmd_manager.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 10:49:20 by fli               #+#    #+#             */
/*   Updated: 2024/06/26 14:02:17 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	cmd_middle_child(int cmd_i, t_pids	**pid_list, char **argv, char **envp)
{
	pid_t	pid_i;
	t_pids	*new_nod;

	new_nod = ft_lstnew_pipex(cmd_i);
	if (new_nod == NULL)
	{
		ft_lstclear_pipex(pid_list);
		return (-1);
	}
	ft_lstadd_back_pipex(pid_list, new_nod);
	if (pipe((new_nod)->pipefd) == -1)
		exit(EXIT_FAILURE);
	pid_i = fork();
	if (pid_i == 0)
	{
		if (cmd_fd_manager(cmd_i, new_nod) == -1)
			return (-1);
		if (cmd_middle_exec(cmd_i, argv, envp) == -1)
			return (-1);
	}
	if (dup2(new_nod->pipefd[0], 0) == -1);
		return (-1);
	close_pipe(new_nod->pipefd);
	new_nod->p_id = pid_i;
	return (new_nod->status);
}

int	cmd_middle_exec(int cmd_i, char **argv, char **envp)
{
	char	**cmd;
	char	*cmd_path;

	cmd = ft_split((const char *)argv[cmd_i], ' ');
	if (cmd == NULL)
		return (-1);
	cmd_path = get_pathname(get_path_tab(envp), cmd[0]);
	if (cmd_path == NULL)
	{
		free(cmd);
		ft_fprintf(2, "%s: command not found\n", argv[cmd_i]);
		return (-1);
	}
	if (cmd_exec(cmd, cmd_path, envp) == -1)
	{
		free(cmd);
		free(cmd_path);
		return (-1);
	}
	return (0);
}
