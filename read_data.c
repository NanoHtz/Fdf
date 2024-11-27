/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalvez- <fgalvez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:11:06 by fgalvez-          #+#    #+#             */
/*   Updated: 2024/11/26 22:21:34 by fgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

//https://github.com/ignacioviseras/Fdf/blob/main/params.c

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		(*f)(i, &s[i]);
		i++;
	}
}

void put_space(unsigned int i, char *s)
{
	(void)i;
	if (*s == '\n')
		*s = ' ';
}

void	free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

int	columns(char *str)
{
	char	*aux;
	char	**split_spaces;
	int		c;

	aux = ft_strdup(str);
	c = 0;
	ft_striteri(aux, put_space);
	split_spaces = ft_split(aux, ' ');//Comprobar aqui si son difitos y el formato ?
	free(aux);
	while(split_spaces[c] != NULL)
		c++;
	free_arr(split_spaces);
	return(c);
}

int read_data(t_content *content, char	*file_name)
{
	int			fd;
	char 		*file;//Puedo llamarlo de otra forma??
	int			error;

	fd = open(file_name, O_RDONLY);//deberia añadir mas flags al open?
    if (fd == -1)
		return(ft_error(ERROR, FD_ERROR, NULL));

	content->map = malloc(sizeof(t_map));
	if(content->map == NULL)
	{
		close(fd);
		return(ft_error(ERROR, MEMORY_ERROR, NULL));
	}
	memset(content->map, 0, sizeof(t_map));
	file = work_on_file(fd, content);
	if(file == NULL)
	{
		free(file);
		free(content->map);
		close(fd);
		return(ft_error(ERROR, "work_on_file", NULL));
	}
	ft_striteri(file, put_space);//Se puede meter en work on file ? otra funcion?
	content->fixed_file = ft_split(file, ' ');
	free(file);
	error = close(fd);
	if(error == -1)//Debemos cerrarlo con protección de errores?
	{
		free(content->map);
		free_arr(content->fixed_file);
		return(ft_error(ERROR, CLOSE_ERROR, NULL));
	}
	return(0);
}
