/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalvez- <fgalvez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 12:04:50 by fgalvez-          #+#    #+#             */
/*   Updated: 2025/03/31 12:04:50 by fgalvez-         ###   ########.fr       */
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
	if (content->ani_flag)
		rot_y(-0.01, content->render_map);
	draw_horizontal_lines(&content->canvas, map, offset);
	draw_vertical_lines(&content->canvas, map, offset);
	mlx_put_image_to_window(content->mlx, content->window,
		content->canvas.mlx_img, 0, 0);
	render_instructions(content, WHITE);
	return (0);
}

int	key_hook1(int keysym, t_core *content)
{
	if (keysym == XK_Escape)
		close_app(content);
	if (keysym == XK_z)
		zoom(content->render_map, 1.2);
	if (keysym == XK_x)
		zoom(content->render_map, 1 / 1.2);
	if (keysym == XK_Left)
		translate(content->render_map, (t_coord){-10, 0, 0, 0});
	if (keysym == XK_Right)
		translate(content->render_map, (t_coord){10, 0, 0, 0});
	if (keysym == XK_Up)
		translate(content->render_map, (t_coord){0, -10, 0, 0});
	if (keysym == XK_Down)
		translate(content->render_map, (t_coord){0, 10, 0, 0});
	if (keysym == XK_w)
		rot_x(-0.1, content->render_map);
	if (keysym == XK_s)
		rot_x(0.1, content->render_map);
	else
		key_hook2(keysym, content);
	return (0);
}

int	key_hook2(int keysym, t_core *content)
{
	if (keysym == XK_n)
	{
		content->palette_id = !content->palette_id;
		restore_map(content);
		isometric(content->render_map);
		scale(content->render_map);
	}
	if (keysym == XK_d)
		rot_y(-0.1, content->render_map);
	if (keysym == XK_a)
		rot_y(0.1, content->render_map);
	if (keysym == XK_k)
		scale_z(content, 1.1);
	if (keysym == XK_j)
		scale_z(content, 1 / 1.1);
	if (keysym == XK_t)
	{
		restore_map(content);
		scale(content->render_map);
	}
	if (keysym == XK_r)
	{
		restore_map(content);
		isometric(content->render_map);
		scale(content->render_map);
	}
	if (keysym == XK_space)
	content->ani_flag ^= 0x1;
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

int	start_mlx(t_core *content)
{
	content->mlx = mlx_init();
	if (content->mlx == NULL)
		ft_putstr_fd("Failed to set up the connection to the X server\n", 2);
	if (content->mlx == NULL)
		return (-1);
	content->window = mlx_new_window(content->mlx, WIN_W, WIN_H, "FdF");
	if (content->window == NULL)
		ft_putstr_fd("Failed to create a new window\n", 2);
	if (content->window == NULL)
		return (-1);
	content->canvas.mlx_img = mlx_new_image(content->mlx, WIN_W, WIN_H);
	content->canvas.addr = mlx_get_data_addr(content->canvas.mlx_img, &content->canvas.bpp,
			&content->canvas.line_len, &content->canvas.endian);
	mlx_loop_hook(content->mlx, loop_hook, content);
	mlx_hook(content->window, DestroyNotify, 0, close_app, content);
	mlx_hook(content->window, KeyPress, 1, key_hook1, content);
	mlx_do_key_autorepeaton(content->mlx);
	mlx_loop(content->mlx);
	return (0);
}
