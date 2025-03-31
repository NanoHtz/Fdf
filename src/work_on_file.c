/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_on_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalvez- <fgalvez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 20:06:31 by fgalvez-          #+#    #+#             */
/*   Updated: 2025/03/28 08:17:35 by fgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/fdf/fdf.h"

void	put_space(unsigned int i, char *s)
{
	(void)i;
	if (*s == '\n')
		*s = ' ';
}

int	columns(char *str)
{
	char	*aux;
	char	**split_spaces;
	int		c;

	aux = ft_strdup(str);
	c = 0;
	ft_striteri(aux, put_space);
	split_spaces = ft_split(aux, ' ');
	free(aux);
	while (split_spaces[c] != NULL)
		c++;
	free_arr(split_spaces);
	return (c);
}

/*
int	columns(char *str)
{
	int	i;
	int	count;
	int	in_word;

	i = 0;
	count = 0;
	in_word = 0;
	while (str[i])
	{
		if ((str[i] != ' ' && str[i] != '\n') && in_word == 0)
		{
			in_word = 1;
			count++;
		}
		else if (str[i] == ' ' || str[i] == '\n')
			in_word = 0;
		i++;
	}
	return (count);
}
*/

int	lines_consistent(int c, t_content *content)
{
	if (content->map->axis_y != 0 && content->map->axis_x != c)
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

char	*work_on_file(int fd, t_content *content)
{
	char	*line;
	char	*file;
	int		c;

	line = "";
	file = malloc(sizeof(char));
	if (file == NULL)
		return (NULL);
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
