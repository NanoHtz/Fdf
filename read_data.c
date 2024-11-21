/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalvez- <fgalvez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:11:06 by fgalvez-          #+#    #+#             */
/*   Updated: 2024/11/21 17:51:14 by fgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

int ft_count_numbers(char *str)
{
	int	i;
	int k;

	i = 0;
	k = 0;
	while(str[i] != '\0')
	{
		if(str[i] == 32)
		{
			k++;
			while(str[i] == 32)
				i++;
		}
		i++;
	}
	return(k + 1);
}

char **mem_for_numbers(t_dim dim)
{
	char	**number;
	int		y;

	y = 0;
	number = malloc(sizeof(char *) * (dim.x + 1));
	if(!number)
		return(NULL);
	while( y < dim.x)
	{
		number[y] = malloc(sizeof(char) * 30);//30 es arbitrario, 1 por cada caracter posible en el string que guarda el numero.
		if (number[y] == NULL)
		{
			while(y >= 0)
			{
				free(number[y]);
				y--;
			}
			free(number);
			return (NULL);
		}
		y++;
	}
	return(number);
}

t_dim	take_dimensions(int fd)
{
	char	*line;
	t_dim	dim;
	
	while ((line = get_next_line(fd)) != NULL)
	{
		dim.x = ft_count_numbers(line);
		dim.y++;
		free(line);
	}
	dim.total = dim.x * dim.y;
	return(dim);
}


char **ft_take_numbers(char **number,char *line)
{
	int		i;
	int		h;
	int		y;
	
	i = 0;
	h = 0;
	y = 0;
	while(line[i] != '\0')
	{
		number[y][h] = line[i];
		if(line[i] == 32)
		{
			number[y][h] = '\0';
			h = 0;
			y++;
			while(line[i] == 32)
				i++;
		}
		number[y][h] = line[i];
		i++;
		h++;
	}
	number[y][h] = '\0';
	number[++y] = NULL;
	return(number);
}

int	*ft_atoi_in_line(char **m_num, t_dim dim)
{
	int *numbers;
	int	i;
	
	i = 0;
	numbers = malloc((sizeof(int) * dim.x));
	if(!numbers)
		free(numbers);
	while(i < dim.x)
	{
		numbers[i] = ft_atoi(m_num[i]);
		i++;
	}
	return(numbers);
}

t_cords	*coords_on_line(int *numbers, t_dim dim)
{
	t_cords *cords;
	int		i;

	i = 0;
	cords = malloc((sizeof(t_cords) * dim.x));
	if(!cords)
		free(cords);

	while(i < dim.x)
	{
		cords[i].z = numbers[i];
		cords[i].x = i;
		i++;
	}
	return(cords);
}

t_cords *take_numbers_on_line(t_dim dim, int fd)
{
	char	**m_num;
	char	*line;
	int		*numbers;
	int		i;
	t_cords	*cords;
	
	i = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		m_num = mem_for_numbers(dim);
		if (!m_num)
		{
			free(line);
			return NULL;
		}
		
		m_num= ft_take_numbers(m_num,line);
		if (!m_num)
		{
			free(line);
			return NULL;
		}
		free(line);
		numbers = ft_atoi_in_line(m_num, dim);
		if (!numbers)
		{
			free(m_num);
			return NULL;
		}
		free(m_num);
		cords = coords_on_line(numbers, dim);
		cords[i].y++;
		if (!cords)
		{
			free(cords);
			return NULL;
		}
		free(numbers);
	}
	return(cords);
}

int read_data(void)
{
	int			fd;
	t_dim		dim;

	fd = open("42.fdf", O_RDONLY);
    if (fd == -1)
    {
        perror("Error opening file");
        return 1;
    }
	dim = take_dimensions(fd);//Se aplica para todo el archivo
	printf("Las dimensiones son:\nNúmero de líneas(y) = %d\nNumero de elementos por línea(x) = %d\nPuntos totales(y*x) = %d\n", dim.y, dim.x, dim.total);
	take_numbers_on_line(dim, fd);
	close(fd);
	return(0);
}