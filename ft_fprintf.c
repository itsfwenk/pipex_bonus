/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 10:30:22 by fli               #+#    #+#             */
/*   Updated: 2024/06/28 17:21:49 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/pipex.h"

void	ft_fprintf_s(va_list arg_ptr, int *count, int fd)
{
	char	*s;

	s = va_arg(arg_ptr, char *);
	if (s == NULL)
	{
		ft_putstr_fd("(null)", fd);
		*count = *count + 6;
		return ;
	}
	ft_putstr_fd(s, fd);
	*count = *count + ft_strlen(s);
}

// void	ft_fprintf_put(const char letter, va_list arg_ptr, int *count, int fd)
// {
// 	if (letter == 's')
// 		ft_fprintf_s(arg_ptr, count, fd);
// }

int	ft_fprintf(int fd, const char *entry, ...)
{
	int		i;
	int		count;
	va_list	arg_ptr;

	if (entry == NULL)
		return (-1);
	va_start(arg_ptr, entry);
	i = 0;
	count = 0;
	while (entry[i] != '\0')
	{
		if (entry[i] == '%' && entry[++i] == 's')
		{
			i++;
			ft_fprintf_s(arg_ptr, &count, fd);
			i++;
		}
		else
		{
			ft_putchar_fd(entry[i], fd);
			count = count + 1;
			i++;
		}
	}
	return (count);
}

void	infile_check(char **argv, int err)
{
	if (err == EACCES)
		ft_fprintf(2, "%s: Permission denied", argv[1]);
	if (err == ENOENT)
		ft_fprintf(2, "%s: No such file or directory", argv[1]);
}
