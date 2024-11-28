/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalvez- <fgalvez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 14:45:30 by fgalvez-          #+#    #+#             */
/*   Updated: 2024/11/28 10:11:30 by fgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/fdf/fdf.h"

int	main(int ac, char **av)
{
	t_content	content;

	if (ac != 2)
		return (ft_error(USAGE));
	if (read_data(&content, av[1]) == -1)
		return (ft_error(READ_ERROR));
	make_map(&content);
	isometric(content.map);
	scale(content.map);
	content.animate_on = 0;
	if (start_mlx(&content) == -1)
		return (-1);
	return (0);
}
