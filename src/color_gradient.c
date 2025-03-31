/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_gradient.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalvez- <fgalvez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 12:09:34 by frafal            #+#    #+#             */
/*   Updated: 2025/03/31 11:14:29 by fgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/fdf/fdf.h"

int	gradient(t_cds act, t_cds base, t_cds final)
{
	int		red;
	int		green;
	int		blue;
	float_t	percentage;

	percentage = percent(fabsf(base.z), fabsf(final.z), fabsf(act.z));
	red = calc_color((base.color >> 16) & 0xFF,
			(final.color >> 16) & 0xFF, percentage);
	green = calc_color((base.color >> 8) & 0xFF,
			(final.color >> 8) & 0xFF, percentage);
	blue = calc_color(base.color & 0xFF, final.color & 0xFF, percentage);
	return ((red << 16) | (green << 8) | blue);
}

t_limits	calculate_limits(int min_z, int max_z)
{
	t_limits	limits;
	int			range;

	range = max_z - min_z;
	limits.l1 = min_z + range * 0.05;
	limits.l2 = min_z + range * 0.4;
	limits.l3 = min_z + range * 0.6;
	limits.l4 = min_z + range * 0.95;
	return (limits);
}

int	get_color_by_z(t_cds act, int min_z, int max_z, t_limits l)
{
	if (act.z <= l.l1)
		return (gradient(act, (t_cds){0, 0, min_z, COLOR_1},
			(t_cds){0, 0, l.l1, COLOR_2}));
	else if (act.z <= l.l2)
		return (gradient(act, (t_cds){0, 0, l.l1, COLOR_2},
			(t_cds){0, 0, l.l2, COLOR_3}));
	else if (act.z <= l.l3)
		return (gradient(act, (t_cds){0, 0, l.l2, COLOR_3},
			(t_cds){0, 0, l.l3, COLOR_4}));
	else if (act.z <= l.l4)
		return (gradient(act, (t_cds){0, 0, l.l3, COLOR_4},
			(t_cds){0, 0, l.l4, COLOR_5}));
	else
		return (gradient(act, (t_cds){0, 0, l.l4, COLOR_5},
			(t_cds){0, 0, max_z, 0xFFFFFF}));
}

void	color_gradient(t_map *map)
{
	int			i;
	t_cds		*act;
	t_limits	limits;

	limits = calculate_limits(map->min_z, map->max_z);
	i = 0;
	while (i < map->axis_x * map->axis_y)
	{
		act = map->arr + i;
		act->color = get_color_by_z(*act, map->min_z, map->max_z, limits);
		i++;
	}
}

int	make_color(t_cds act, t_cds base, t_cds final, t_cds gamma)
{
	int		red;
	int		green;
	int		blue;
	float_t	percentage;

	if (act.color == final.color)
		return (act.color);
	if (gamma.x > gamma.y)
		percentage = percent(base.x, final.x, act.x);
	else
		percentage = percent(base.y, final.y, act.y);
	red = calc_color((base.color >> 16) & 0xFF,
			(final.color >> 16) & 0xFF, percentage);
	green = calc_color((base.color >> 8) & 0xFF,
			(final.color >> 8) & 0xFF, percentage);
	blue = calc_color(base.color & 0xFF, final.color & 0xFF, percentage);
	return ((red << 16) | (green << 8) | blue);
}
