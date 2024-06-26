/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trash.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 11:39:30 by fli               #+#    #+#             */
/*   Updated: 2024/06/19 17:13:28 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// int	input_file_count(char *file1)
// {
// 	int		fd;
// 	int		count;
// 	int		read_return;
// 	char	buf[2];

// 	fd = open((const char *)file1, O_RDONLY);
// 	if (fd == -1)
// 		return (-1);
// 	read_return = read(fd, buf, 1);
// 	if (read_return < 0)
// 		return (-2);
// 	buf[1] = '\0';
// 	count = 0;
// 	while (buf[0] != '\0')
// 	{
// 		count++;
// 		read_return = read(fd, buf, 1);
// 		if (read_return <= 0)
// 			return (close(fd), count);
// 		buf[1] = '\0';
// 	}
// 	return (close(fd), count);
// }
