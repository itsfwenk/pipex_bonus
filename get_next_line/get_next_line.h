/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 16:41:56 by fli               #+#    #+#             */
/*   Updated: 2024/06/05 14:22:57 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1

# endif

typedef struct s_list
{
	int				min;
	int				max;
	char			s[BUFFER_SIZE + 1];
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);

int		end_line(t_list **current);

int		count_char(t_list **lst);

t_list	*ft_lstnew(int fd, t_list **init);

void	ft_lstadd_back(t_list **lst, t_list *new);

char	*ft_strdup(t_list **init, char **gnl);

void	ft_lstclear(t_list **lst);

void	ft_lstdelone(t_list **lst);

#endif
