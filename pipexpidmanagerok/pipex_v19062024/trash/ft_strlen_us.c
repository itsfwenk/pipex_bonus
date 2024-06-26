/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 17:41:58 by fli               #+#    #+#             */
/*   Updated: 2024/06/17 17:25:25 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

size_t	ft_strlen_us(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != ' ')
	{
		i++;
	}
	return (i);
}

/* #include <stdio.h>
int	main()
{
	const char	oui[4] = "oui";
	printf("%zu\n", ft_strlen(oui));
} */
