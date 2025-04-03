/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalvez- <fgalvez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 11:05:54 by fgalvez-          #+#    #+#             */
/*   Updated: 2025/04/03 11:05:54 by fgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/fdf/fdf.h"

int	init_mlx(t_core *con)
{
	con->mlx = mlx_init();
	if (con->mlx == NULL)
		return (-1);
	return (0);
}

int	create_window(t_core *con)
{
	con->window = mlx_new_window(con->mlx, WIN_W, WIN_H, "FdF");
	if (con->window == NULL)
		return (-1);
	return (0);
}

void	init_canvas(t_img *canvas, void *mlx)
{
	canvas->mlx_img = mlx_new_image(mlx, WIN_W, WIN_H);
	canvas->addr = mlx_get_data_addr(canvas->mlx_img,
			&canvas->bpp, &canvas->line_len, &canvas->endian);
}

void	setup_hooks(t_core *con)
{
	mlx_loop_hook(con->mlx, loop_hook, con);
	mlx_hook(con->window, DestroyNotify, 0, fdf_esc, con);
	mlx_hook(con->window, KeyPress, 1, controls_1, con);
	mlx_do_key_autorepeaton(con->mlx);
}

int	start_mlx(t_core *con)
{
	if (init_mlx(con) != 0)
		return (-1);
	if (create_window(con) != 0)
		return (-1);
	init_canvas(&con->canvas, con->mlx);
	setup_hooks(con);
	mlx_loop(con->mlx);
	return (0);
}
