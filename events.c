/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalvez- <fgalvez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 14:32:34 by fgalvez-          #+#    #+#             */
/*   Updated: 2024/09/09 18:40:03 by fgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	clean_and_close(t_cwin *cw)
{
	mlx_destroy_window(cw->mlx, cw->window);
	mlx_destroy_display(cw->mlx);
	free(cw->mlx);
	free(cw);
	exit(1);
}

int	scape(int keysym, t_cwin *cw)
{
	if (keysym == XK_Escape)
		clean_and_close(cw);
	return (0);
}

int	out(t_cwin *cw)
{
	clean_and_close(cw);
	return (0);
}

void	events(t_cwin *cw)
{
	mlx_key_hook(cw->window, scape, cw);
	mlx_hook(cw->window, 17, 0L, out, cw);
	mlx_loop(cw->mlx);
}
