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
