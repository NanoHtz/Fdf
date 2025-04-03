/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalvez- <fgalvez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 19:59:36 by fgalvez-          #+#    #+#             */
/*   Updated: 2025/04/03 11:06:42 by fgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/fdf/fdf.h"

int	loop_hook(t_core *core)
{
	t_coord		center;
	t_grid		*grid;

	if (core->window == NULL)
		return (1);
	grid = core->render_map;
	center.x = WIN_W / 2;
	center.y = WIN_H / 2;
	center.z = 0;
	fill_layer(&core->canvas, BLACK);
	if (core->ani_flag == 1)
		rot_y(-0.01, grid);
	draw_horizontal_lines(&core->canvas, grid, center);
	draw_vertical_lines(&core->canvas, grid, center);
	mlx_put_image_to_window(core->mlx, core->window,
		core->canvas.mlx_img, 0, 0);
	return (0);
}

int	controls_1(int keysym, t_core *content)
{
	if (keysym == XK_Escape)
		fdf_esc(content);
	return (0);
}

void	free_all(t_core *content)
{
	if (content->render_map)
	{
		free(content->render_map->arr);
		free(content->render_map);
	}
	if (content->map_backup)
	{
		free(content->map_backup->arr);
		free(content->map_backup);
	}
	if (content->parsed_map)
		free_arr(content->parsed_map);
	if (content->mlx)
		free(content->mlx);
}

int	fdf_esc(t_core *content)
{
	mlx_destroy_window(content->mlx, content->window);
	content->window = NULL;
	mlx_destroy_image(content->mlx, content->canvas.mlx_img);
	mlx_destroy_display(content->mlx);
	free_all(content);
	exit(0);
	return (0);
}
