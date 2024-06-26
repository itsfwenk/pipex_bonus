/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_manager.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 10:25:55 by fli               #+#    #+#             */
/*   Updated: 2024/06/29 20:22:40 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/pipex.h"

// int	here_doc_checker(char **argv, int *cmd_i)
// {
// 	// int	fd_hd;

// 	if (ft_strncmp(argv[1], "here_doc", ft_strlen("here_doc")) == 0)
// 	{
// 		// fd_hd = if_here_doc(argv);
// 		*cmd_i = 3;
// 		return (1);
// 	}
// 	*cmd_i = 2;
// 	return (-11);
// }

int	ft_strncmp_pipex(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n < 1 || !s1)
		return (0);
	i = 0;
	while (i < n && (s1[i] != '\0' || s2[i] != '\0'))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

int	if_here_doc(char **argv)
{
	int		fd_hd;
	char	*next_line;
	char	*limiter;

	limiter = ft_strjoin(argv[2], "\n");
	if (limiter == NULL)
		return (-1);
	fd_hd = open("here_doc", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd_hd == -1)
		return (-1);
	next_line = get_next_line(0);
	while (ft_strncmp_pipex(next_line, limiter, ft_strlen(limiter)) != 0)
	{
		write(fd_hd, next_line, ft_strlen(next_line));
		free(next_line);
		next_line = get_next_line(0);
	}
	free(limiter);
	free(next_line);
	get_next_line(-1);
	close(fd_hd);
	return (0);
}
