/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_data2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalvez- <fgalvez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 20:06:31 by fgalvez-          #+#    #+#             */
/*   Updated: 2024/11/26 22:24:05 by fgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*work_on_file(int fd, t_content *content)
{
	char	*line;
	char	*file;
	int		c;

	line = "";//Si utilizo Null no lee el archivo//fdf-francis -> line = "";//Puedo eliminar esto y poner char *line {0}?
	file = malloc(sizeof(char));
	if(file == NULL)
		return(NULL);
	file[0] = '\0';
	content->map->axis_y = 0;
	while (line != NULL)
	{
		line = get_next_line(fd);
		if (line != NULL)
		{
			c = columns(line);
			if (!lines_consistent(c, content))
				return (NULL);
			content->map->axis_x = c;
			content->map->axis_y += 1;
			add_line(&line, &file);
		}
	}
	return (file);
}

int	lines_consistent(int c, t_content *content)
{
	if (content->map->axis_y != 0 && content->map->axis_x != c)
	{
		return (0);
	}
	return (1);
}

void	add_line(char **line, char **file)
{
	char	*tmp;

	tmp = *file;
	*file = ft_strjoin(tmp, *line);
	//free(tmp);
	free(*line);
	*line = "";//""
}
