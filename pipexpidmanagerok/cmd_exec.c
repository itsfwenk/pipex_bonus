/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_exec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 13:53:13 by fli               #+#    #+#             */
/*   Updated: 2024/06/25 15:34:20 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/pipex.h"
#include "libft.h"

int	cmd_exec(char **cmd, char *cmd_path, char **envp)
{
	if (execve(cmd_path, (char *const*)cmd, (char *const *)envp) == -1)
		return (-1);
	return (0);
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

int	cmd2_exec(char **argv, char **envp)
{
	char	**cmd2;
	char	*cmd2_path;

	cmd2 = ft_split((const char *)argv[3], ' ');
	if (cmd2 == NULL)
		return (-1);
	cmd2_path = get_pathname(get_path_tab(envp), cmd2[0]);
	if (cmd2_path == NULL)
	{
		free(cmd2);
		ft_fprintf(2, "%s: command not found\n", argv[3]);
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
