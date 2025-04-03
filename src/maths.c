/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalvez- <fgalvez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 20:26:17 by fgalvez-          #+#    #+#             */
/*   Updated: 2025/04/03 10:59:01 by fgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/fdf/fdf.h"

float	add(float a, float b)
{
	return (a + b);
}

float	subtract(float a, float b)
{
	return (a - b);
}

t_coord	mult_vec(t_mrot matrix, t_coord point)
{
	t_coord	r;

	r.x = point.x * matrix.i1j1 + point.y * matrix.i2j1 + point.z * matrix.i3j1;
	r.y = point.x * matrix.i1j2 + point.y * matrix.i2j2 + point.z * matrix.i3j2;
	r.z = point.x * matrix.i1j3 + point.y * matrix.i2j3 + point.z * matrix.i3j3;
	r.color = point.color;
	return (r);
}

t_coord	sum_vec(t_coord point1, t_coord point2)
{
	t_coord	sum;

	sum.x = add(point1.x, point2.x);
	sum.y = add(point1.y, point2.y);
	sum.z = add(point1.z, point2.z);
	sum.color = point1.color;
	return (sum);
}

t_coord	diff_vec(t_coord point1, t_coord point2)
{
	t_coord	diff;

	diff.x = subtract(point1.x, point2.x);
	diff.y = subtract(point1.y, point2.y);
	diff.z = subtract(point1.z, point2.z);
	diff.color = point1.color;
	return (diff);
}
