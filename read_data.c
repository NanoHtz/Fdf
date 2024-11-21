/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalvez- <fgalvez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:11:06 by fgalvez-          #+#    #+#             */
/*   Updated: 2024/11/19 14:11:06 by fgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

int	get_width(char *line)
{
	int		i;
	int		k;

	k = 0;
	i = 0;
	if(!line)
		return(ERROR_READING);

	while(line[i] != '\0')
	{
		if(line[i] == 32)
		{
			while(line[i] == 32)
				i++;
			k++;
		}
		i++;
	}
	return(k + 1);
}

char	**take_numbers(char *line, t_dim dim)
{
	char	**coords;
	int		i;
	int		k;
	int		j;

	k = 0;
	i = 0;
	j = 0;
	//if(!line)
		//return(ERROR_READING);
	coords = malloc(sizeof(char *) * dim.v_x);
	if(coords == NULL)
		return NULL;

	while(k < dim.v_x)
	{
		coords[k] = malloc(sizeof(char) * 30); // Asumiendo un tamaño máximo por número.
		if (!coords[k])
		{
    		while (k >= 0)
        		free(coords[k--]);
    		free(coords);
    		return (NULL);
		}
		k++;
	}

	k = 0;
	while(line[i] != '\0')
	{
		if(line[i] == 32)
		{
			coords[k][j] = '\0';
			j = 0;
			k++;
			while(line[i] == 32)
				i++;
		}
		else
		{
			coords[k][j] = line[i];
			i++;
			j++;
		}
	}
	coords[k][j] = '\0';
	return(coords);
}

t_dim take_dim_and_data(int fd, t_dim dim)
{
	char	***numbers;
	char	**number;
	char	*line;
	int		k;
	int		y;
    int		line_capacity;

	dim.v_y = 0;
	line_capacity = 10;
	line = get_next_line(fd);
	if(!line)
		return(dim);
	dim.v_x = get_width(line);
	free(line);

	numbers = malloc(sizeof(char **) * line_capacity); // Asumimos 1000 líneas máximo. Puedes ajustar dinámicamente si es necesario.
	if (!numbers)
		return (dim);

	while ((line = get_next_line(fd)) != NULL)
	{
		if (dim.v_y >= line_capacity)
        {
            line_capacity *= 2;
            numbers = realloc(numbers, sizeof(char **) * line_capacity);
            if (!numbers)
                return (dim);
        }

		number = take_numbers(line, dim);
		if (!number)
		{
			free(line);
			while (dim.v_y > 0)
			{
				dim.v_y--;
				for (k = 0; k < dim.v_x; k++)
					free(numbers[dim.v_y][k]);
				free(numbers[dim.v_y]);
			}
			free(numbers);
			return (dim);
		}
		numbers[dim.v_y] = number;
		free(line);
		dim.v_y++;
	}

	y = 0;
	while (k < dim.v_x)
	{
		k = 0;
		printf("Línea %d:\n", y + 1);
		while (k < dim.v_x && numbers[y][k]) // Imprimir cada número de la línea.
		{
			printf("%s ", numbers[y][k]);
			free(numbers[y][k]); // Liberar cada número.
			k++;
		}
		free(numbers[y]); // Liberar la línea completa.
		printf("\n");
		y++;
	}
	free(numbers);

	printf("\nEl número de lineas es: %d\n", dim.v_y);
	printf("\nNumeros por linea: %d\n", dim.v_x);
	printf("\nElementos totales de la matriz: %d\n", dim.v_x * dim.v_y);
	return (dim);
}

int read_data(void)
{
	int		fd;
	t_dim	dim;

	fd = open("42.fdf", O_RDONLY);
    if (fd == -1)
    {
        perror("Error opening file");
        return 1;
    }
	dim = take_dim_and_data(fd, dim);
	close(fd);
	return(0);
}
