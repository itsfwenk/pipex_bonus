/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 11:02:22 by fli               #+#    #+#             */
/*   Updated: 2024/05/29 15:39:47 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_unsigned(unsigned int nb, const char *base, int *count)
{
	if (nb < ft_strlen(base))
	{
		ft_putchar_fd(base[nb % ft_strlen(base)], 1);
		*count = *count + 1;
	}
	if (nb >= ft_strlen(base))
	{
		ft_putnbr_unsigned((nb / ft_strlen(base)), base, count);
		ft_putnbr_unsigned((nb % ft_strlen(base)), base, count);
	}
}
