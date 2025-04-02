/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hsv.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalvez- <fgalvez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 20:55:15 by fgalvez-          #+#    #+#             */
/*   Updated: 2025/04/01 20:55:15 by fgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/fdf/fdf.h"

t_palette	get_palette(int id)
{
	t_palette	p;

	if (id == 1)
	{
		p.c1 = 0x003366;
		p.c2 = 0x336666;
		p.c3 = 0x339933;
		p.c4 = 0xCCCC33;
		p.c5 = 0x996633;
		p.c6 = 0xEEEEEE;
	}
	else
	{
		p.c1 = 0x6A0DAD;
		p.c2 = 0xFF00FF;
		p.c3 = 0xFF69B4;
		p.c4 = 0xFFD700;
		p.c5 = 0xFF4500;
		p.c6 = 0xFFFFFF;
	}
	return (p);
}
