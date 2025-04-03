/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalvez- <fgalvez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 11:09:00 by fgalvez-          #+#    #+#             */
/*   Updated: 2025/04/03 11:09:00 by fgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/fdf/fdf.h"

int	controls_1(int keysym, t_core *content)
{
	if (keysym == XK_z)
		zoom(content->render_map, 1.2);
	else if (keysym == XK_x)
		zoom(content->render_map, 1 / 1.2);
	else if (keysym == XK_Left)
		move(content->render_map, (t_coord){-10, 0, 0, 0});
	else if (keysym == XK_Right)
		move(content->render_map, (t_coord){10, 0, 0, 0});
	else if (keysym == XK_Up)
		move(content->render_map, (t_coord){0, -10, 0, 0});
	else if (keysym == XK_Down)
		move(content->render_map, (t_coord){0, 10, 0, 0});
	else if (keysym == XK_z)
		zoom(content->render_map, 1.2);
	else if (keysym == XK_x)
		zoom(content->render_map, 1 / 1.2);
	else if (keysym == XK_w)
		rot_x(-0.1, content->render_map);
	else if (keysym == XK_s)
		rot_x(0.1, content->render_map);
	else if (keysym == XK_Escape)
		fdf_esc(content);
	else
		controls_2(keysym, content);
	return (0);
}

void	color_mode(t_core *content)
{
	content->palette_id = !content->palette_id;
	restore_map(content);
	isometric(content->render_map);
	scale(content->render_map);
}

void	transform(t_core *content)
{
	restore_map(content);
	scale(content->render_map);
}

void	restart(t_core *content)
{
	restore_map(content);
	isometric(content->render_map);
	scale(content->render_map);
}

int	controls_2(int keysym, t_core *content)
{
	if (keysym == XK_n)
		color_mode(content);
	else if (keysym == XK_d)
		rot_y(-0.1, content->render_map);
	else if (keysym == XK_a)
		rot_y(0.1, content->render_map);
	else if (keysym == XK_k)
		scale_z(content, 1.1);
	else if (keysym == XK_j)
		scale_z(content, 1 / 1.1);
	else if (keysym == XK_t)
		transform(content);
	else if (keysym == XK_space)
		content->ani_flag ^= 0x1;
	else if (keysym == XK_r)
		restart(content);
	return (0);
}
