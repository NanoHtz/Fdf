/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalvez- <fgalvez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 14:45:30 by fgalvez-          #+#    #+#             */
/*   Updated: 2024/11/26 23:14:53 by fgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char **av)
{
	t_content content;//check

	if (ac != 2)
		return (ft_error(ERROR, ARGS, USAGE, NULL));
	if(read_data(&content, av[1]) == -1)
		return (ft_error(ERROR, READ_ERROR , NULL));
	make_map(&content);//alomejor con &content
	isometric(content.map);
	scale(content.map);
	content.animate_on = 0;
	if (start_mlx(&content) == -1)// o quizas &cw, &content
		return (-1);
	return (0);
}
