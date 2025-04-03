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

int	init_mlx(t_core *content)
{
	content->mlx = mlx_init();
	if (content->mlx == NULL)
	{
		ft_putstr_fd("Error\n", 2);
		return (-1);
	}
	return (0);
}

int	create_window(t_core *content)
{
	content->window = mlx_new_window(content->mlx, WIN_W, WIN_H, "FdF");
	if (content->window == NULL)
	{
		ft_putstr_fd("Error to make window\n", 2);
		return (-1);
	}
	return (0);
}

void	init_canvas(t_img *canvas, void *mlx)
{
	canvas->mlx_img = mlx_new_image(mlx, WIN_W, WIN_H);
	canvas->addr = mlx_get_data_addr(canvas->mlx_img,
			&canvas->bpp, &canvas->line_len, &canvas->endian);
}

void	setup_hooks(t_core *content)
{
	mlx_loop_hook(content->mlx, loop_hook, content);
	mlx_hook(content->window, DestroyNotify, 0, fdf_esc, content);
	mlx_hook(content->window, KeyPress, 1, controls_1, content);
	mlx_do_key_autorepeaton(content->mlx);
}

int	start_mlx(t_core *content)
{
	if (init_mlx(content) != 0)
		return (-1);
	if (create_window(content) != 0)
		return (-1);
	init_canvas(&content->canvas, content->mlx);
	setup_hooks(content);
	mlx_loop(content->mlx);
	return (0);
}
