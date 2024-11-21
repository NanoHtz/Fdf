/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalvez- <fgalvez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 14:45:30 by fgalvez-          #+#    #+#             */
/*   Updated: 2024/11/12 19:10:14 by fgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
RECURSOS: Guia basica:
https://github.com/suspectedoceano/mlx
https://harm-smits.github.io/42docs/libs/minilibx
https://github.com/qst0/ft_libgfx
https://gontjarow.github.io/MiniLibX/
https://aurelienbrabant.fr/blog/getting-started-with-the-minilibx
https://medium.com/@alaricsaltzman913/fdf-42-a-detailed-walkthrough-7184cca317fc
https://github.com/VBrazhnik/FdF?tab=readme-ov-file
https://web.archive.org/web/20160325100729/http://freespace.virgin.net/hugo.elias/graphics/x_main.htm
https://www.geeksforgeeks.org/anti-aliased-line-xiaolin-wus-algorithm/
https://rosettacode.org/wiki/Xiaolin_Wu's_line_algorithm
https://web.archive.org/web/20160408133525/http://freespace.virgin.net/hugo.elias/graphics/x_wuline.htm

*/

#include "fdf.h"

t_cwin	*init()
{
	t_cwin		*cw;

	cw = malloc(sizeof(t_cwin));
	if (cw == NULL)
		return (NULL);
	cw->mlx = mlx_init();
	if (cw->mlx == NULL)
	{
		free(cw);
		return (NULL);
	}
	cw->window = mlx_new_window(cw->mlx, WIDTH, HEIGHT, "Prueba");
	if (cw->window == NULL)
	{
		mlx_destroy_display(cw->mlx);
		free(cw);
		return (NULL);
	}
	return (cw);
}

int	main(int argc, char **argv)
{
	t_cwin		*cw;

	if (argc != 2)//Comprobación de los argumentos
		return (ARGS_ERROR);
	printf("\nEl argumento introducido es : %s\n", argv[1]);

	cw = init();//Inicializamos la minilibx y la ventana.
	if (cw == NULL)
		return(1);

	menu(cw);
	line(cw);
	read_data();
	events(cw);
	clean_and_close(cw);
}
