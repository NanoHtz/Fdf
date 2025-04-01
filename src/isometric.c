/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalvez- <fgalvez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 20:47:21 by fgalvez-          #+#    #+#             */
/*   Updated: 2025/04/01 19:47:10 by fgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/fdf/fdf.h"

void	rot_y(float_t angle, t_grid *map)
{
	t_mrot	rotating_y;

	rotating_y = (t_mrot){
		cos(angle), 0, sin(angle),
		0, 1, 0,
		-sin(angle), 0, cos(angle)};
	change_map(rotating_y, map);
}

void	rot_x(float_t angle, t_grid *map)
{
	t_mrot	rotating_x;

	rotating_x = (t_mrot){
		1, 0, 0,
		0, cos(angle), -sin(angle),
		0, sin(angle), cos(angle)};
	change_map(rotating_x, map);
}

void	isometric(t_grid *map)
{
	rot_x(-M_PI_2, map);
	rot_y(M_PI_4, map);
	rot_x(ISO, map);
}
