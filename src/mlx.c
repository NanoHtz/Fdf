/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalvez- <fgalvez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 19:59:36 by fgalvez-          #+#    #+#             */
/*   Updated: 2025/04/01 12:21:42 by fgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/fdf/fdf.h"

int	loop_hook(t_core *content)
{
	t_grid	*map;
	t_coord	offset;

	if (content->window == NULL)
		return (1);
	render_background(&content->canvas, BLACK);
	map = content->render_map;
	offset.x = WIN_W / 2;
	offset.y = WIN_H / 2;
	offset.z = 0;
	draw_map(&content->canvas, map, offset);
	mlx_put_image_to_window(content->mlx, content->window,
		content->canvas.mlx_img, 0, 0);
	return (0);
}

int	key_hook1(int keysym, t_core *content)
{
	if (keysym == XK_Escape)
		close_app(content);
	return (0);
}

int	close_app(t_core *content)
{
	mlx_destroy_window(content->mlx, content->window);
	content->window = NULL;
	mlx_destroy_image(content->mlx, content->canvas.mlx_img);
	mlx_destroy_display(content->mlx);
	free(content->render_map->arr);
	free(content->render_map);
	free(content->map_backup->arr);
	free(content->map_backup);
	free(content->mlx);
	free_arr(content->parsed_map);
	exit(0);
	return (0);
}

int	start_mlx(t_core *con)
{
	con->mlx = mlx_init();
	if (con->mlx == NULL)
		return (-1);
	con->window = mlx_new_window(con->mlx, WIN_W, WIN_H, "FdF");
	if (con->window == NULL)
		return (-1);
	con->canvas.mlx_img = mlx_new_image(con->mlx, WIN_W, WIN_H);
	con->canvas.addr = mlx_get_data_addr(con->canvas.mlx_img, &con->canvas.bpp,
			&con->canvas.line_len, &con->canvas.endian);
	mlx_loop_hook(con->mlx, loop_hook, con);
	mlx_hook(con->window, DestroyNotify, 0, close_app, con);
	mlx_hook(con->window, KeyPress, 1, key_hook1, con);
	mlx_do_key_autorepeaton(con->mlx);
	mlx_loop(con->mlx);
	return (0);
}
