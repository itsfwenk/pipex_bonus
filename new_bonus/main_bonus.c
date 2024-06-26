/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 10:02:34 by fli               #+#    #+#             */
/*   Updated: 2024/06/26 11:44:56 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int		cmd_i;
	t_pids	*pid_list;

	if (argc != 5)
		return (0);
	pid_list = NULL;
	if (cmd1_child(&pid_list, argv, envp) == -10)
		exit(EXIT_FAILURE);
	cmd_i = 3;
	while (cmd_i < (argc - 2))
	{
		cmd_middle_child(cmd_i, argv, envp);
		cmd_i++;
	}
	if (cmd2_child(cmd_i, &pid_list, argv, envp) == -1)
		exit(EXIT_FAILURE);
	wait_pids(&pid_list);
	ft_lstclear_pipex(&pid_list);
}
