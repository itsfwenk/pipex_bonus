/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_exec_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 13:16:49 by fli               #+#    #+#             */
/*   Updated: 2024/06/25 13:41:29 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/pipex.h"

int	cmdn_child(int cmdn, int pipefd[2], char **argv, char **envp)
{
	int		childn_status = 0;
	pid_t	pidn;

	dprintf(2, "in function %s, cmd : %s\n", __func__, argv[cmdn]);
	pidn = fork();
	if (pidn == 0)
	{
		// dprintf(2, "in child post fork in function %s, cmd : %s\n", __func__, argv[cmdn]);
		if (dup2(pipefd[0], 0) == -1)
			return (-1);
		if (dup2(pipefd[1], 1) == -1)
			return (-1);
		close_pipe(pipefd);
		if (cmdn_exec(cmdn, argv, envp) == -1)
			return (-1);
	}
	dprintf(2, "post fork in function %s, cmd : %s\n", __func__, argv[cmdn]);
	// waitpid(pidn, &childn_status, 0);
	return (childn_status);
}

int	cmdn_exec(int cmdn, char **argv, char **envp)
{
	char	**cmd;
	char	*cmd_path;

	cmd = ft_split((const char *)argv[cmdn], ' ');
	if (cmd == NULL)
		return (-1);
	cmd_path = get_pathname(get_path_tab(envp), cmd[0]);
	if (cmd_path == NULL)
	{
		free(cmd);
		ft_fprintf(2, "%s: command not found\n", argv[cmdn]);
		return (-1);
	}
	dprintf(2, "++in function %s, cmd : %s\n", __func__, argv[cmdn]);
	if (cmd_exec(cmd, cmd_path, envp) == -1)
	{
		free(cmd);
		free(cmd_path);
		return (-1);
	}
	return (0);
}
