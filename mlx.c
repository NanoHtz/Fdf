/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalvez- <fgalvez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 19:59:36 by fgalvez-          #+#    #+#             */
/*   Updated: 2024/11/26 20:35:24 by fgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
	draw_map(&content->img, map, offset);
	mlx_put_image_to_window(content->mlx, content->window,
		content->img.mlx_img, 0, 0);
	return (0);
}

int	key_hook1(int keysym, t_content *content)
{
	if (keysym == XK_Escape)
		close_app(content);
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
		return(-1);

	content->window = mlx_new_window(content->mlx, WIN_W, WIN_H, "FdF");
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
