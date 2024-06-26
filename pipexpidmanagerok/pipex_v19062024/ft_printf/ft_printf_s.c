/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 13:44:18 by fli               #+#    #+#             */
/*   Updated: 2024/05/29 14:49:23 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_s(va_list arg_ptr, int *count)
{
	char	*s;

	s = va_arg(arg_ptr, char *);
	if (s == NULL)
	{
		ft_putstr_fd("(null)", 1);
		*count = *count + 6;
		return ;
	}
	ft_putstr_fd(s, 1);
	*count = *count + ft_strlen(s);
}
