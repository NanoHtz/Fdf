/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalvez- <fgalvez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 19:59:36 by fgalvez-          #+#    #+#             */
/*   Updated: 2024/11/29 13:14:37 by fgalvez-         ###   ########.fr       */
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

int	start_mlx(t_content *con)
{
	con->mlx = mlx_init();
	if (con->mlx == NULL)
		return (-1);
	con->window = mlx_new_window(con->mlx, WIN_W, WIN_H, "FdF");
	if (con->window == NULL)
		return (-1);
	con->img.mlx_img = mlx_new_image(con->mlx, WIN_W, WIN_H);
	con->img.addr = mlx_get_data_addr(con->img.mlx_img, &con->img.bpp,
			&con->img.line_len, &con->img.endian);
	mlx_loop_hook(con->mlx, loop_hook, con);
	mlx_hook(con->window, DestroyNotify, 0, close_app, con);
	mlx_hook(con->window, KeyPress, 1, key_hook1, con);
	mlx_do_key_autorepeaton(con->mlx);
	mlx_loop(con->mlx);
	return (0);
}
