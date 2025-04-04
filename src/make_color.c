/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalvez- <fgalvez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 19:56:44 by fgalvez-          #+#    #+#             */
/*   Updated: 2025/04/01 19:56:44 by fgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/fdf/fdf.h"

int	make_color(t_coord act, t_coord base, t_coord final, t_coord gamma)
{
	int		red;
	int		green;
	int		blue;
	float_t	percentage;

	if (act.color == final.color)
		return (act.color);
	if (gamma.x > gamma.y)
		percentage = get_percentage(base.x, final.x, act.x);
	else
		percentage = get_percentage(base.y, final.y, act.y);
	red = interpolate_color((base.color >> 16) & 0xFF,
			(final.color >> 16) & 0xFF, percentage);
	green = interpolate_color((base.color >> 8) & 0xFF,
			(final.color >> 8) & 0xFF, percentage);
	blue = interpolate_color(base.color & 0xFF, final.color & 0xFF, percentage);
	return ((red << 16) | (green << 8) | blue);
}
