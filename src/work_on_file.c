/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_on_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalvez- <fgalvez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 20:06:31 by fgalvez-          #+#    #+#             */
/*   Updated: 2025/04/01 12:44:47 by fgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/fdf/fdf.h"

int	columns(char *str)
{
	char	*aux;
	char	**split_spaces;
	int		c;

	aux = ft_strdup(str);
	c = 0;
	parse_line(str);
	split_spaces = ft_split(aux, ' ');
	free(aux);
	while (split_spaces[c] != NULL)
		c++;
	free_arr(split_spaces);
	return (c);
}

int	lines_consistent(int c, t_core *content)
{
	if (content->render_map->axis_y != 0 && content->render_map->axis_x != c)
		return (0);
	return (1);
}

void	add_line(char **line, char **file)
{
	char	*tmp;

	tmp = *file;
	*file = ft_strjoin(tmp, *line);
	free(*line);
	*line = "";
}

char	*work_on_file(int fd, t_core *content)
{
	char	*line;
	char	*file;
	int		c;

	line = "";
	file = malloc(sizeof(char));
	if (file == NULL)
		return (NULL);
	file[0] = '\0';
	content->render_map->axis_y = 0;
	while (line != NULL)
	{
		line = get_next_line(fd);
		if (line != NULL)
		{
			c = columns(line);
			if (!lines_consistent(c, content))
				return (NULL);
			content->render_map->axis_x = c;
			content->render_map->axis_y += 1;
			add_line(&line, &file);
		}
	}
	return (file);
}
