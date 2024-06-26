/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 10:30:22 by fli               #+#    #+#             */
/*   Updated: 2024/05/30 12:56:26 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_printf_put(const char letter, va_list arg_ptr, int *count)
{
	if (letter == 'c')
		ft_printf_c(arg_ptr, count);
	if (letter == 's')
		ft_printf_s(arg_ptr, count);
	if (letter == 'p')
		ft_printf_p(arg_ptr, count);
	if (letter == 'd')
		ft_printf_d(arg_ptr, count);
	if (letter == 'i')
		ft_printf_d(arg_ptr, count);
	if (letter == 'u')
		ft_printf_u(arg_ptr, count);
	if (letter == 'x')
		ft_printf_x(arg_ptr, count);
	if (letter == 'X')
		ft_printf_bigx(arg_ptr, count);
	if (letter == '%')
	{
		ft_putchar_fd('%', 1);
		*count = *count + 1;
	}
}

int	ft_printf(const char *entry, ...)
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
		if (entry[i] == '%')
		{
			i++;
			ft_printf_put(entry[i], arg_ptr, &count);
			i++;
		}
		else
		{
			ft_putchar_fd(entry[i], 1);
			count = count + 1;
			i++;
		}
	}
	return (count);
}

/* #include <stdio.h>
int	main()
{
	//char c = 'f';
	int true = printf("bonjour%%\n");
	printf("%d\n", true);
	printf("%p\n", &true);
	//printf("%d\n", 2147483649);
	int testnultrue = printf("bonjour %p", NULL);
	printf("%d\n", testnultrue);

	int perso = ft_printf("bonjour%%\n");
	ft_printf("%d\n", perso);
	ft_printf("%p\n", &true);
	//ft_printf("%d\n", 2147483649);
	int testnulperso = printf("bonjour %p", NULL);
	printf("%d\n", testnulperso);
} */
/*#include <stdio.h>
int	main()
{
	// printf(" %x ", -1);
	ft_printf("%d\n", ft_printf(NULL));
	//printf("%d\n", printf(NULL));
}*/
