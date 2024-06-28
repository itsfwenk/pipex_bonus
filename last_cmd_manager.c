/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_cmd_manager.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 11:31:49 by fli               #+#    #+#             */
/*   Updated: 2024/06/28 14:27:41 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/pipex.h"

int	cmd2_child(int cmd_i, t_pids	**pid_list, char **argv, char **envp)
{
	pid_t	pid2;
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
	pid2 = fork();
	if (pid2 == 0)
	{
		if (cmd2_fd_manager(cmd_i, argv, new_nod) == -1)
			return (-1);
		if (cmd2_exec(cmd_i, argv, envp) == -1)
			exit(EXIT_FAILURE);
	}
	close_pipe(new_nod->pipefd);
	new_nod->p_id = pid2;
	return (new_nod->status);
}

int	cmd2_exec(int cmd_i, char **argv, char **envp)
{
	char	**cmd2;
	char	*cmd2_path;

	cmd2 = ft_split((const char *)argv[cmd_i], ' ');
	if (cmd2 == NULL)
		return (-1);
	cmd2_path = get_pathname(envp, cmd2[0]);
	if (cmd2_path == NULL)
	{
		free(cmd2);
		ft_fprintf(2, "%s: command not found\n", argv[cmd_i]);
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
