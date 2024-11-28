/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mates.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalvez- <fgalvez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 20:26:17 by fgalvez-          #+#    #+#             */
/*   Updated: 2024/11/28 10:19:36 by fgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/fdf/fdf.h"

t_cds	vec_add(t_cds pt1, t_cds pt2)
{
	t_cds	sum;

	sum.x = pt1.x + pt2.x;
	sum.y = pt1.y + pt2.y;
	sum.z = pt1.z + pt2.z;
	sum.color = pt1.color;
	return (sum);
}

t_cds	vec_sub(t_cds pt1, t_cds pt2)
{
	t_cds	diff;

	diff.x = pt1.x - pt2.x;
	diff.y = pt1.y - pt2.y;
	diff.z = pt1.z - pt2.z;
	diff.color = pt1.color;
	return (diff);
}

t_cds	vector_multiplication(t_mrotacional matrix, t_cds point)
{
	t_cds	r;

	r.x = point.x * matrix.i1j1 + point.y * matrix.i2j1 + point.z * matrix.i3j1;
	r.y = point.x * matrix.i1j2 + point.y * matrix.i2j2 + point.z * matrix.i3j2;
	r.z = point.x * matrix.i1j3 + point.y * matrix.i2j3 + point.z * matrix.i3j3;
	r.color = point.color;
	return (r);
}
