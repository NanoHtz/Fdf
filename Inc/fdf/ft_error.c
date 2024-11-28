/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalvez- <fgalvez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 21:16:53 by fgalvez-          #+#    #+#             */
/*   Updated: 2024/11/27 18:24:57 by fgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"

/*Write string in terminal follow with newline*/
void	ft_strendl(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}
/*Personalizar esta funcion con: valor de retorno, fd, color,
argumentos variables Para ello quizas deba recibir y devolver
una estructura
ademas de repasar primero la lista de argumentos variables*/

int	ft_error(const char *str_1)
{
	write(1, "\033[31m", 5);
	ft_strendl(str_1);
	write(1, "\033[31m", 4);
	return (-1);
}
