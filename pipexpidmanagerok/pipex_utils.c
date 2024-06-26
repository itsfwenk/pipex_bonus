/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 11:40:12 by fli               #+#    #+#             */
/*   Updated: 2024/06/25 11:48:28 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft.h"

 char	*get_pathname(char **path_tab, char *cmd)
{
	int		i;
	char	*pathname_cmd;

	i = 0;
	while (path_tab[i] != NULL)
	{
		pathname_cmd = ft_strjoin_pipex((char const *)path_tab[i], (char const *)cmd);
		if (pathname_cmd == NULL)
			return (NULL);
		if (access(pathname_cmd, X_OK) == 0)
			return (pathname_cmd);
		i++;
		free(pathname_cmd);
	}
	return (NULL);
}

int	tab_len(char **path_tab)
{
	int	tab_len;

	tab_len = 0;
	while (path_tab[tab_len] != NULL)
		tab_len++;
	return (tab_len);
}

char	**get_path_tab(char **envp)
{
	int			i;
	int			first_len;
	char		*path_s;
	char		**path_tab;

	if (!*envp || !envp)
		return (NULL);
	i = 0;
	while (envp[i] != NULL)
	{
		if (envp[i][0] == 'P' && envp[i][1] == 'A'
			&& envp[i][2] == 'T' && envp[i][3] == 'H')
		{
			path_s = envp[i];
			break;
		}
		i++;
	}
	path_tab = ft_split(path_s, ':');
	if (path_tab == NULL)
		return (NULL);
	first_len = ft_strlen(path_tab[0] + 5);
	ft_memmove(path_tab[0], path_tab[0] + 5, ft_strlen(path_tab[0] + 5));
	ft_bzero(path_tab[0] + first_len, ft_strlen(path_tab[0]) - first_len);
	return (path_tab);
}
void	close_pipe(int pipefd[2])
{
	close(pipefd[0]);
	close(pipefd[1]);
}
