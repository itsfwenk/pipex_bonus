/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 10:02:34 by fli               #+#    #+#             */
/*   Updated: 2024/06/27 17:38:43 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/pipex.h"


int	cmd_exec(char **cmd, char *cmd_path, char **envp)
{
	if (execve(cmd_path, (char *const*)cmd, (char *const *)envp) == -1)
		return (-1);
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	int		cmd_i;
	t_pids	*pid_list;

	if (argc < 5)
		return (0);
	cmd_i = 2;
	pid_list = NULL;
	if (here_doc_checker(argv) != -11)
		if_here_doc(argv);
	if (cmd1_child(cmd_i, &pid_list, argv, envp) == -10)
		exit(EXIT_FAILURE);
	cmd_i++;
	if (here_doc_checker(argv) != -11)
		cmd_i++;
	while (cmd_i < (argc - 2))
	{
		cmd_middle_child(cmd_i, &pid_list, argv, envp);
		cmd_i++;
	}
	if (cmd2_child(cmd_i, &pid_list, argv, envp) == -1)
		exit(EXIT_FAILURE);
	if (here_doc_checker(argv) != -11)
		unlink("here_doc");
	wait_pids(&pid_list);
	ft_lstclear_pipex(&pid_list);
}
