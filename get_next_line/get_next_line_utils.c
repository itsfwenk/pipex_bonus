/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 16:56:56 by fli               #+#    #+#             */
/*   Updated: 2024/06/06 17:04:08 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*ft_lstnew(int fd, t_list **init)
{
	int		read_return;
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (new == NULL)
		return (NULL);
	read_return = read(fd, new->s, BUFFER_SIZE);
	if (read_return < 0 || (read_return == 0 && !*init))
	{
		free(new);
		return (NULL);
	}
	(new->s)[read_return] = '\0';
	new->min = 0;
	new->max = read_return;
	new->next = NULL;
	return (new);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!lst || !new)
		return ;
	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	last = *lst;
	while (last != NULL)
	{
		if ((last->next) == NULL)
		{
			last->next = new;
			return ;
		}
		last = last->next;
	}
}

char	*ft_strdup(t_list **init, char **gnl)
{
	int		j;
	t_list	*pos;

	*gnl = malloc((1 + count_char(init)) * sizeof(char));
	if (*gnl == NULL)
		return (NULL);
	j = 0;
	pos = *init;
	while (pos && pos->min <= pos->max)
	{
		if ((pos->s)[pos->min] == '\0')
		{
			ft_lstdelone(init);
			pos = *init;
			continue ;
		}
		if ((pos->s)[pos->min] == '\n')
		{
			(*gnl)[j++] = (pos->s)[(pos->min)++];
			break ;
		}
		(*gnl)[j++] = (pos->s)[(pos->min)++];
	}
	(*gnl)[j] = '\0';
	return (*gnl);
}

void	ft_lstclear(t_list **lst)
{
	t_list	*temp;

	if (!lst || !*lst)
		return ;
	while (*lst != NULL)
	{
		temp = (*lst)->next;
		free(*lst);
		*lst = temp;
	}
}

void	ft_lstdelone(t_list **lst)
{
	t_list	*temp;

	if (!lst)
		return ;
	temp = (*lst)->next;
	free(*lst);
	*lst = temp;
}
