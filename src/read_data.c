/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalvez- <fgalvez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:11:06 by fgalvez-          #+#    #+#             */
/*   Updated: 2025/04/01 12:44:42 by fgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/fdf/fdf.h"
#include <stdlib.h>

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

void	parse_line(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			str[i] = ' ';
		i++;
	}
}

char	**ft_parse_and_split(char *str)
{
	if (!str)
		return (NULL);
	parse_line(str);
	return (ft_split(str, ' '));
}

int	read_data(t_core *content, char	*file_name)
{
	int			fd;
	char		*file;
	int			error;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (ft_error(FD_ERROR));
	content->render_map = malloc(sizeof(t_grid));
	if (content->render_map == NULL)
		return (close_and_report(MEMORY_ERROR_R, fd));
	ft_memset(content->render_map, 0, sizeof(t_grid));
	file = work_on_file(fd, content);
	if (file == NULL)
		return (free_close_report(MEMORY_ERROR_R, fd, content, file));
	content->parsed_map = ft_parse_and_split(file);
	free(file);
	error = close(fd);
	if (error == -1)
	{
		free(content->render_map);
		free_arr(content->parsed_map);
		return (ft_error(CLOSE_ERROR));
	}
	return (0);
}
