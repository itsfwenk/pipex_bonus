/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 14:28:52 by fli               #+#    #+#             */
/*   Updated: 2024/05/29 15:11:33 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"

int		ft_printf(const char *entry, ...) __attribute__((format(printf, 1, 2)));

void	ft_printf_c(va_list arg_ptr, int *count);

void	ft_printf_s(va_list arg_ptr, int *count);

void	ft_printf_p(va_list arg_ptr, int *count);

void	ft_printf_d(va_list(arg_ptr), int *count);

void	ft_printf_u(va_list arg_ptr, int *count);

void	ft_printf_x(va_list(arg_ptr), int *count);

void	ft_printf_bigx(va_list(arg_ptr), int *count);

void	ft_putnbr_base(int nb, const char *base, int *count);

void	ft_putnbr_unsigned(unsigned int nb, const char *base, int *count);

void	ft_putptr(unsigned long nbr, const char *base, int *count);

void	ft_putnbr_base(int nb, const char *base, int *count);

void	ft_putnbr_unsigned(unsigned int nb, const char *base, int *count);

#endif
