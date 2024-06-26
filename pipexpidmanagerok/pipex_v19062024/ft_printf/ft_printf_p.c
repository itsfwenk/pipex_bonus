/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 13:53:48 by fli               #+#    #+#             */
/*   Updated: 2024/05/29 15:22:43 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_p(va_list arg_ptr, int *count)
{
	unsigned long	p;

	p = va_arg(arg_ptr, unsigned long);
	if (p == 0)
	{
		ft_putstr_fd("(nil)", 1);
		*count = *count + 5;
	}
	else
	{
		ft_putchar_fd('0', 1);
		ft_putchar_fd('x', 1);
		*count = *count + 2;
		ft_putptr(p, "0123456789abcdef", count);
	}
}
