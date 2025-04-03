/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalvez- <fgalvez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 20:28:34 by fgalvez-          #+#    #+#             */
/*   Updated: 2025/04/03 11:04:42 by fgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/fdf/fdf.h"

float	ft_fabsf(float x)
{
	if (x < 0)
		return (-x);
	return (x);
}

int	draw_h(t_img *img, t_coord start, t_coord end)
{
	t_coord	act;
	t_coord	diff;
	int		accum;
	int		fi;

	fi = 1;
	diff = diff_vec(end, start);
	if (diff.x < 0)
		fi = -1;
	diff.x = ft_fabsf(diff.x);
	accum = 2 * diff.x - diff.y;
	act = start;
	while (act.y <= end.y)
	{
		act.color = make_color(act, start, end, diff);
		my_pixel_put(img, act);
		if (accum > 0)
		{
			act.x += fi;
			accum -= 2 * diff.y;
		}
		accum += 2 * diff.x;
		act.y++;
	}
	return (0);
}

int	draw_l(t_img *img, t_coord start, t_coord end)
{
	t_coord	act;
	t_coord	diff;
	int		accum;
	int		chi;

	chi = 1;
	diff = diff_vec(end, start);
	if (diff.y < 0)
		chi = -1;
	diff.y = ft_fabsf(diff.y);
	accum = 2 * diff.y - diff.x;
	act = start;
	while (act.x <= end.x)
	{
		act.color = make_color(act, start, end, diff);
		my_pixel_put(img, act);
		if (accum > 0)
		{
			act.y += chi;
			accum -= 2 * diff.x;
		}
		accum += 2 * diff.y;
		act.x++;
	}
	return (0);
}

int	draw_bresenham(t_img *img, t_coord start, t_coord end)
{
	float	y;
	float	x;

	y = end.y - start.y;
	x = end.x - start.x;
	if (ft_fabsf(y) < ft_fabsf(x))
	{
		if (x < 0)
			return (draw_l(img, end, start));
		return (draw_l(img, start, end));
	}
	if (y < 0)
		return (draw_h(img, end, start));
	return (draw_h(img, start, end));
	return (-1);
}
