/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 14:46:04 by fli               #+#    #+#             */
/*   Updated: 2024/06/25 15:33:57 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include "libft.h"

typedef struct s_pids
{
	pid_t				p_id;
	int				status;
	struct s_pids	*next;
}	t_pids;

int		cmd_exec(char **cmd, char *cmd_path, char **envp);

int		cmd1_exec(char **argv, char **envp);

int		cmd2_exec(char **argv, char **envp);

char	*ft_strjoin_pipex(char const *s1, char const *s2);

char	*get_pathname(char **path_tab, char *cmd);

int		tab_len(char **path_tab);

char	**get_path_tab(char **envp);

int		cmd1_child(t_pids	**pid_list, int pipefd[2], char **argv, char **envp);

int		cmd2_child(t_pids	**pid_list, int pipefd[2], char **argv, char **envp);

int		main(int argc, char **argv, char **envp);

void	ft_fprintf_s(va_list arg_ptr, int *count, int fd);

void	ft_fprintf_put(const char letter, va_list arg_ptr, int *count, int fd);

int		ft_fprintf(int fd, const char *entry, ...);

void	close_pipe(int pipefd[2]);

void	infile_check(char **argv, int err);

int	cmdn_child(int cmdn, int pipefd[2], char **argv, char **envp);

int	cmdn_exec(int cmdn, char **argv, char **envp);

void	print_content(int fd);

void	ft_lstclear_pipex(t_pids **lst);

t_pids	*ft_lstnew_pipex(pid_t p_id);

void	ft_lstadd_back_pipex(t_pids **lst, t_pids *n);

void	wait_pids(t_pids **lst);

#endif
