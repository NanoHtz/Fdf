/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mates.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalvez- <fgalvez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 20:26:17 by fgalvez-          #+#    #+#             */
/*   Updated: 2024/11/27 16:26:25 by fgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}


void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	if (s == NULL)
		return ;
	i = 0;
	while (s[i] != '\0')
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}

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
	t_cds	result;

	result.x = point.x * matrix.i1j1 + point.y * matrix.i2j1 + point.z * matrix.i3j1;
	result.y = point.x * matrix.i1j2 + point.y * matrix.i2j2 + point.z * matrix.i3j2;
	result.z = point.x * matrix.i1j3 + point.y * matrix.i2j3 + point.z * matrix.i3j3;
	result.color = point.color;
	return (result);
}
