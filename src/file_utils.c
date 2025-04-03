/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalvez- <fgalvez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 16:37:55 by fgalvez-          #+#    #+#             */
/*   Updated: 2025/04/02 16:37:55 by fgalvez-         ###   ########.fr       */
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
