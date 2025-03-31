/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points_on_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalvez- <fgalvez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 21:14:31 by fgalvez-          #+#    #+#             */
/*   Updated: 2025/03/28 09:00:49 by fgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/fdf/fdf.h"

void	z_range(t_map *map, t_cds *act)
{
	if (act->z < map->min_z)
		map->min_z = act->z;
	if (act->z > map->max_z)
		map->max_z = act->z;
}

void	values(t_map *map, t_content *content, t_cds *point)
{
	if (map->axis_x <= 0 || map->axis_y <= 0
		|| map->arr == NULL || content->fixed_file == NULL)
	{
		ft_report_void(MAP_P);
		return ;
	}
	point->z = 0;
	point->y = -map->space * map->axis_y / 2;
}

static void	process_point(t_cds *act, t_context *ctx, int index)
{
	*act = ctx->point;
	if (index < ctx->map->axis_x * ctx->map->axis_y
		&& ctx->content->fixed_file[index] != NULL)
		act->z = ft_atoi(ctx->content->fixed_file[index]);
	else
	{
		ft_putstr_fd("Error: Invalid data in fixed_file.\n", 2);
		act->z = 0;
	}
	z_range(ctx->map, act);
	act->color = PURPLE;
}

static void	process_row(t_context *ctx)
{
	int		j;
	t_cds	*act;

	j = 0;
	ctx->point.x = -ctx->map->space * ctx->map->axis_x / 2;
	while (j < ctx->map->axis_x)
	{
		act = ctx->map->arr + ctx->i * ctx->map->axis_x + j;
		process_point(act, ctx, ctx->i * ctx->map->axis_x + j);
		ctx->point.x += ctx->map->space;
		j++;
	}
}

void	points_on_map(t_content *content, t_map *map)
{
	t_context	ctx;

	ctx.content = content;
	ctx.map = map;
	values(ctx.map, ctx.content, &ctx.point);
	ctx.i = 0;
	while (ctx.i < ctx.map->axis_y)
	{
		process_row(&ctx);
		ctx.point.y += ctx.map->space;
		ctx.i++;
	}
}
