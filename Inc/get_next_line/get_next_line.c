/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalvez- <fgalvez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 14:03:52 by fgalvez-          #+#    #+#             */
/*   Updated: 2024/11/19 18:10:24 by fgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "../libft/libft.h"

char	*ft_read(int fd, char *str)
{
	char	*bff;
	int		bytes;

	bff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!bff)
		return (NULL);
	bytes = 1;
	while (!ft_strchr(str, '\n') && bytes != 0)
	{
		bytes = read(fd, bff, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(bff);
			free(str);
			return (NULL);
		}
		bff[bytes] = '\0';
		str = ft_strjoin(str, bff);
	}
	free(bff);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*ln;
	static char	*str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	str = ft_read(fd, str);
	if (!str)
		return (0);
	ln = ft_line(str);
	str = ft_nextstr(str);
	return (ln);
}
