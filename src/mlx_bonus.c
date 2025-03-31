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

int	loop_hook(t_content *content)
{
	t_map	*map;
	t_cds	offset;

	if (content->window == NULL)
		return (1);
	render_background(&content->img, BLACK);
	map = content->map;
	offset.x = WIN_W / 2;
	offset.y = WIN_H / 2;
	offset.z = 0;
	if (content->animate_on)
		rot_y(-0.01, content->map);
	draw_map(&content->img, map, offset);
	mlx_put_image_to_window(content->mlx, content->window,
		content->img.mlx_img, 0, 0);
	render_instructions(content, WHITE);
	return (0);
}

int	key_hook1(int keysym, t_content *content)
{
	if (keysym == XK_Escape)
		close_app(content);
	if (keysym == XK_equal)
		zoom(content->map, 1.2);
	if (keysym == XK_minus)
		zoom(content->map, 1 / 1.2);
	if (keysym == XK_Left)
		translate(content->map, (t_cds){-10, 0, 0, 0});
	if (keysym == XK_Right)
		translate(content->map, (t_cds){10, 0, 0, 0});
	if (keysym == XK_Up)
		translate(content->map, (t_cds){0, -10, 0, 0});
	if (keysym == XK_Down)
		translate(content->map, (t_cds){0, 10, 0, 0});
	if (keysym == XK_w)
		rot_x(-0.1, content->map);
	if (keysym == XK_s)
		rot_x(0.1, content->map);
	else
		key_hook2(keysym, content);
	return (0);
}

int	key_hook2(int keysym, t_content *content)
{
	if (keysym == XK_d)
		rot_y(-0.1, content->map);
	if (keysym == XK_a)
		rot_y(0.1, content->map);
	if (keysym == XK_k)
		scale_z(content, 1.1);
	if (keysym == XK_j)
		scale_z(content, 1 / 1.1);
	if (keysym == XK_t)
	{
		restore_map(content);
		scale(content->map);
	}
	if (keysym == XK_r)
	{
		restore_map(content);
		isometric(content->map);
		scale(content->map);
	}
	if (keysym == XK_space)
	content->animate_on ^= 0x1;
	return (0);
}

int	close_app(t_content *content)
{
	mlx_destroy_window(content->mlx, content->window);
	content->window = NULL;
	mlx_destroy_image(content->mlx, content->img.mlx_img);
	mlx_destroy_display(content->mlx);
	free(content->map->arr);
	free(content->map);
	free(content->original_map->arr);
	free(content->original_map);
	free(content->mlx);
	free_arr(content->fixed_file);
	exit(0);
	return (0);
}

int	start_mlx(t_content *content)
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
	content->img.mlx_img = mlx_new_image(content->mlx, WIN_W, WIN_H);
	content->img.addr = mlx_get_data_addr(content->img.mlx_img, &content->img.bpp,
			&content->img.line_len, &content->img.endian);
	mlx_loop_hook(content->mlx, loop_hook, content);
	mlx_hook(content->window, DestroyNotify, 0, close_app, content);
	mlx_hook(content->window, KeyPress, 1, key_hook1, content);
	mlx_do_key_autorepeaton(content->mlx);
	mlx_loop(content->mlx);
	return (0);
}
