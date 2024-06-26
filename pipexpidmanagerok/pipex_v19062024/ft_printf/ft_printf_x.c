/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 11:12:10 by fli               #+#    #+#             */
/*   Updated: 2024/05/29 16:00:44 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_x(va_list(arg_ptr), int *count)
{
	unsigned int	x;

	x = va_arg(arg_ptr, unsigned int);
	ft_putnbr_unsigned(x, "0123456789abcdef", count);
}
