/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalvez- <fgalvez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 12:09:34 by frafal            #+#    #+#             */
/*   Updated: 2024/11/25 16:44:53 by fgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float_t	percent(int base, int final, int act)
{
	float_t	pos;
	float_t	gamma;

	gamma = final - base;
	if (gamma == 0)
		return (1.0);
	pos = act - base;
	return (pos / gamma);
}

int	calc_color(int base, int final, float_t percent)
{
	int	color;

	color = (1 - percent) * base + percent * final;
	return (color);
}

int	make_color(t_cds act, t_cds base, t_cds final, t_cds gamma)
{
	int		red;
	int		green;
	int		blue;
	float_t	percentage;

	if (act.color == final.color)
		return (act.color);
	if (gamma.x > gamma.y)
		percentage = percent(base.x, final.x, act.x);
	else
		percentage = percent(base.y, final.y, act.y);
	red = calc_color((base.color >> 16) & 0xFF,
			(final.color >> 16) & 0xFF, percentage);
	green = calc_color((base.color >> 8) & 0xFF,
			(final.color >> 8) & 0xFF, percentage);
	blue = calc_color(base.color & 0xFF, final.color & 0xFF, percentage);
	return ((red << 16) | (green << 8) | blue);
}

int	gradient(t_cds act, t_cds base, t_cds final)
{
	int		red;
	int		green;
	int		blue;
	float_t	percentage;

	percentage = percent(fabsf(base.z), fabsf(final.z), fabsf(act.z));
	red = calc_color((base.color >> 16) & 0xFF,
			(final.color >> 16) & 0xFF, percentage);
	green = calc_color((base.color >> 8) & 0xFF,
			(final.color >> 8) & 0xFF, percentage);
	blue = calc_color(base.color & 0xFF, final.color & 0xFF, percentage);
	return ((red << 16) | (green << 8) | blue);
}
