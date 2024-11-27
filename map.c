/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalvez- <fgalvez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 21:14:31 by fgalvez-          #+#    #+#             */
/*   Updated: 2024/11/27 16:31:09 by fgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map *make_map(t_content *content)
{
	t_map	*map;

	map = content->map;
	map->max_z = 0;
	map->min_z = 0;
	map->i = (t_cds){1, 0, 0, 0x0};
	map->j = (t_cds){0, 1, 0, 0x0};
	map->k = (t_cds){0, 0, 1, 0x0};

	if (map->axis_x <= 0 || map->axis_y <= 0)
	{
    ft_putstr_fd("Error: Invalid map dimensions.\n", 2);
    return (NULL);
	}
	map->arr = malloc(map->axis_x * map-> axis_y * sizeof(t_cds));
	if(map->arr ==NULL)
	{
		ft_putstr_fd("Error: Memory allocation failed.\n", 2);
		return(NULL);
	}
	map->space = 10;//Se le puede cambiar el nombre ?
	points_on_map(content, map);
	color_gradient(map);//Necesitamos cambiar color_handingls
	save_original_map(content);//Esta funcion es necesaria ???
	return (map);
}

t_map	*save_original_map(t_content *content)
{
	t_cds	*act;
	int		i;

	content->original_map = malloc(sizeof(t_map));
	if (content->original_map == NULL)
		return (NULL);
	content->original_map->arr = malloc(content->map->axis_x
			* content->map->axis_y * sizeof(t_cds));
	if (content->original_map->arr == NULL)
		return (NULL);
	i = 0;
	while (i < content->map->axis_x * content->map->axis_y)
	{
		act = content->map->arr + i;
		*(content->original_map->arr + i) = *act;
		i++;
	}
	return (content->original_map);
}

void points_on_map(t_content *content, t_map *map)
{
	int		i;
	int		j;
	t_cds	*act;
	t_cds	point;


    if (map->axis_x <= 0 || map->axis_y <= 0 || map->arr == NULL || content->fixed_file == NULL)
    {
		ft_putstr_fd("Error: Invalid map or content data.\n", 2);
        return;
    }

	point.z = 0;
	point.y = -map->space * map->axis_y / 2;
	i = 0;
	while( i < map->axis_y)
	{
		point.x = -map->space * map->axis_x / 2;
		j = 0;
		while(j < map->axis_x)
		{
			act = map->arr + i * map->axis_x + j;
			*act = point;
			if (i * map->axis_x + j < map->axis_x * map->axis_y && content->fixed_file[i * map->axis_x + j] != NULL)
			{
				act->z = ft_atoi(content->fixed_file[i * map->axis_x + j]);
			}
			else
			{
				ft_putstr_fd("Error: Invalid data in fixed_file.\n", 2);
				act->z = 0; // Asignar un valor predeterminado
			}
			act ->z = ft_atoi(content->fixed_file[i * map->axis_x + j]);
			z_range(map, act);
			act->color = PURPLE;
			point.x += map->space;
			j++;
		}
		point.y += map->space;
		i++;
	}
}

void	z_range(t_map *map, t_cds *act)
{
	if (act->z < map->min_z)
		map->min_z = act->z;
	if (act->z > map->max_z)
		map->max_z = act->z;
}

void	color_gradient(t_map *map)
{
	t_cds	base;
	t_cds	max;
	t_cds	min;
	t_cds	*act;
	int		i;
	//cambiar esta estructura
	base = (t_cds){0, 0, 0, PURPLE};
	max = (t_cds){0, 0, map->max_z, HIGH_PURPLE};
	min = (t_cds){0, 0, map->min_z, LOW_PURPLE};
	i = 0;
	while (i < map->axis_x * map->axis_y)
	{
		act = map->arr + i;
		if (act->z > 0)
			act->color = gradient(*act, base, max);
		if (act->z < 0)
			act->color = gradient(*act, base, min);
		i++;
	}
}

