/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalvez- <fgalvez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 14:45:30 by fgalvez-          #+#    #+#             */
/*   Updated: 2025/04/01 12:18:08 by fgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/fdf/fdf.h"

int	main(int ac, char **av)
{
	t_core	content;

	if (ac != 2)
		return (ft_error(USAGE));
	if (read_data(&content, av[1]) == -1)
		return (ft_error(READ_ERROR));
	make_map(&content);
	isometric(content.render_map);
	scale(content.render_map);
	content.ani_flag = 0;
	if (start_mlx(&content) == -1)
		return (-1);
	return (0);
}
