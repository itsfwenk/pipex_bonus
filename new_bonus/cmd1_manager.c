/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd1_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 10:56:56 by fli               #+#    #+#             */
/*   Updated: 2024/06/26 14:02:15 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	cmd1_child(int cmd_i, t_pids	**pid_list, char **argv, char **envp)
{
	pid_t	pid1;
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
	pid1 = fork();
	if (pid1 == 0)
	{
		if (cmd1_fd_manager(argv, &pid_list) == -10)
			return (-10);
		if (cmd1_exec(argv, envp) == -1)
			return (-1);
	}
	if (dup2(new_nod->pipefd[0], 0) == -1);
		return (-1);
	close_pipe(new_nod->pipefd);
	new_nod->p_id = pid1;
	return (new_nod->status);
}

int	cmd1_exec(char **argv, char **envp)
{
	char	**cmd1;
	char	*cmd1_path;

	cmd1 = ft_split((const char *)argv[2], ' ');
	if (cmd1 == NULL)
		return (-1);
	cmd1_path = get_pathname(get_path_tab(envp), cmd1[0]);
	if (cmd1_path == NULL)
	{
		free(cmd1);
		ft_fprintf(2, "%s: command not found\n", argv[2]);
		return (-1);
	}
	if (cmd_exec(cmd1, cmd1_path, envp) == -1)
	{
		free(cmd1);
		free(cmd1_path);
		return (-1);
	}
	return (0);
}
