/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalvez- <fgalvez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 11:06:25 by fgalvez-          #+#    #+#             */
/*   Updated: 2025/03/31 11:06:25 by fgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/fdf/fdf.h"

int	interpolate_color(int from, int to, float_t ratio)
{
	return ((1 - ratio) * from + ratio * to);
}

float_t	get_percentage(int min, int max, int current)
{
	float_t	range;
	float_t	position;

	range = max - min;
	if (range == 0)
		return (1.0);
	position = current - min;
	return (position / range);
}
