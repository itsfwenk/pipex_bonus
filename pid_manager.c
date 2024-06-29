/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pid_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 14:22:36 by fli               #+#    #+#             */
/*   Updated: 2024/06/30 01:24:54 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/pipex.h"

t_pids	*ft_lstnew_pipex(int cmd_i)
{
	t_pids	*n;

	n = malloc(sizeof(t_pids));
	if (n == NULL)
		return (NULL);
	n->cmd_i = cmd_i;
	n->status = 0;
	n->next = NULL;
	return (n);
}

void	ft_lstadd_back_pipex(t_pids **lst, t_pids *n)
{
	t_pids	*last;

	if (!lst || !n)
		return ;
	if (!(*lst))
	{
		*lst = n;
		return ;
	}
	last = *lst;
	while (last != NULL)
	{
		if ((last->next) == NULL)
		{
			last->next = n;
			return ;
		}
		last = last->next;
	}
}

void	ft_lst_new_add_back_pipex(pid_t p_id, t_pids **lst)
{
	t_pids	*n;

	n = ft_lstnew_pipex(p_id);
	if (n == NULL)
		return ;
	ft_lstadd_back_pipex(lst, n);
}

void	ft_lstclear_pipex(t_pids **lst)
{
	t_pids	*temp;

	if (!lst || !*lst)
		return ;
	while (*lst != NULL)
	{
		temp = (*lst)->next;
		free(*lst);
		*lst = temp;
	}
}

void	wait_pids(t_pids **lst, char **argv)
{
	t_pids	*temp;

	if (!lst || !*lst)
		return ;
	temp = *lst;
	while (temp != NULL)
	{
		waitpid(temp->p_id, &(temp->status), 0);
		dprintf(2, "child %d status %d\n", temp->cmd_i, WEXITSTATUS(temp->status));
		if (WEXITSTATUS(temp->status) == 255)
		{
			write(2, argv[temp->cmd_i], ft_strlen(argv[temp->cmd_i]));
			write(2, ": command not found\n", ft_strlen(": command not found\n"));
		}
		temp = temp->next;
	}
}
