/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalvez- <fgalvez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:11:06 by fgalvez-          #+#    #+#             */
/*   Updated: 2025/03/27 16:29:56 by fgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/fdf/fdf.h"
#include <stdlib.h>

//https://github.com/ignacioviseras/Fdf/blob/main/params.c

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		(*f)(i, &s[i]);
		i++;
	}
}

void	free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

char	**ft_split_putspace(char *str)
{
	if (!str)
		return (NULL);
	ft_striteri(str, put_space);
	return (ft_split(str, ' '));
}

int	read_data(t_content *content, char	*file_name)
{
	int			fd;
	char		*file;
	int			error;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (ft_error(FD_ERROR));
	content->map = malloc(sizeof(t_map));
	if (content->map == NULL)
		return (close_and_report(MEMORY_ERROR_R, fd));
	ft_memset(content->map, 0, sizeof(t_map));
	file = work_on_file(fd, content);
	if (file == NULL)
		return (free_close_report(MEMORY_ERROR_R, fd, content, file));
	ft_striteri(file, put_space);
	content->fixed_file = ft_split(file, ' ');
	/*
	ft_striteri(file, put_space);
	content->fixed_file = ft_split(file, ' ');
	por esto->content->fixed_file = ft_split_putspace(file);
	*/
	free(file);
	error = close(fd);
	if (error == -1)
	{
		free(content->map);
		free_arr(content->fixed_file);
		return (ft_error(CLOSE_ERROR));
	}
	return (0);
}
