/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 13:55:40 by fli               #+#    #+#             */
/*   Updated: 2024/05/29 15:38:29 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	ft_putnbr_base(int nb, const char *base, int *count)
{
	if (nb < 0)
	{
		ft_putchar_fd('-', 1);
		*count = *count + 1;
		if (nb == -2147483648)
		{
			ft_putchar_fd(base[2 % (int)ft_strlen(base)], 1);
			*count = *count + 1;
			nb = 147483648;
		}
		else
			nb = nb * (-1);
	}
	if (nb < (int)ft_strlen(base))
	{
		ft_putchar_fd(base[nb % (int)ft_strlen(base)], 1);
		*count = *count + 1;
	}
	if (nb >= (int)ft_strlen(base))
	{
		ft_putnbr_base((nb / (int)ft_strlen(base)), base, count);
		ft_putnbr_base((nb % (int)ft_strlen(base)), base, count);
	}
}
