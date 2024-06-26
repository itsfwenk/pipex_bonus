/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bigx.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 11:19:29 by fli               #+#    #+#             */
/*   Updated: 2024/05/29 16:00:42 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_bigx(va_list(arg_ptr), int *count)
{
	unsigned int	bigx;

	bigx = va_arg(arg_ptr, unsigned int);
	ft_putnbr_unsigned(bigx, "0123456789ABCDEF", count);
}
