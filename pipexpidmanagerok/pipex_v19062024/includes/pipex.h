/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 14:46:04 by fli               #+#    #+#             */
/*   Updated: 2024/06/19 16:54:45 by fli              ###   ########.fr       */
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

int		cmd_exec(char **cmd, char *cmd_path, char **envp);

int		cmd1_exec(char **argv, char **envp);

int		cmd2_exec(char **argv, char **envp);

char	*ft_strjoin_pipex(char const *s1, char const *s2);

char	*get_pathname(char **path_tab, char *cmd);

int		tab_len(char **path_tab);

char	**get_path_tab(char **envp);

int		cmd1_child(int pipefd[2], char **argv, char **envp);

int		cmd2_child(int pipefd[2], char **argv, char **envp);

int		main(int argc, char **argv, char **envp);

#endif
