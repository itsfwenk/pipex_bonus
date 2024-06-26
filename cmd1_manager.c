/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd1_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 10:56:56 by fli               #+#    #+#             */
/*   Updated: 2024/06/30 01:19:07 by fli              ###   ########.fr       */
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
		cmd1_exec(new_nod->cmd_i, argv, envp);
	}
	if (dup2(new_nod->pipefd[0], STDIN_FILENO) == -1)
		return (-1);
	close_pipe(new_nod->pipefd);
	new_nod->p_id = pid1;
	return (new_nod->status);
}

void	cmd1_exec(int cmd_i, char **argv, char **envp)
{
	char	**cmd1;
	char	*cmd1_path;

	cmd1 = ft_split((const char *)argv[cmd_i], ' ');
	if (cmd1 == NULL)
		return ;
	cmd1_path = get_pathname(envp, cmd1[0]);
	if (cmd1_path == NULL)
	{
		free(cmd1);
		exit(-1);
	}
	if (cmd_exec(cmd1, cmd1_path, envp) == -1)
	{
		free(cmd1);
		free(cmd1_path);
		exit(EXIT_FAILURE);
	}
}
