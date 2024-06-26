/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:38:49 by fli               #+#    #+#             */
/*   Updated: 2024/05/29 15:09:08 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putptr(unsigned long nbr, const char *base, int *count)
{
	if (nbr < ft_strlen(base))
	{
		ft_putchar_fd(base[nbr % ft_strlen(base)], 1);
		*count = *count + 1;
	}
	if (nbr >= ft_strlen(base))
	{
		ft_putptr((nbr / ft_strlen(base)), base, count);
		ft_putptr((nbr % ft_strlen(base)), base, count);
	}
}
