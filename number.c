#include <stdio.h>
#include <stdlib.h>

int ft_strlen(char *str)
{
	int	i;

	i = 0;
	while(str[i] != '\0')
		i++;
	return(i);
}

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

char **ft_take_numbers(char *str)
{
	char	**number;
	int		y;
	int		k;
	int		i;
	int		h;

	i = 0;
	y = 0;
	h = 0;
	k = ft_count_numbers(str);

	number = malloc(sizeof(char *) * (k + 1));
	if(!number)
		return(NULL);

	while( y <= k)
	{
		number[y] = malloc(sizeof(char) * 30);
		if (number[y] == NULL)
			return (NULL);
		y++;
	}
	number[y] = NULL;
	y = 0;
	while(str[i] != '\0')
	{
		number[y][h] = str[i];
		if(str[i] == 32)
		{
			number[y][h] = '\0';
			h = 0;
			y++;
			while(str[i] == 32)
				i++;
		}
		number[y][h] = str[i];
		i++;
		h++;
	}
	number[y][h] = '\0';
	return(number);
}

int	main(void)
{
	char	**numbers;
	char 	*line;
	int		n;
	int		i;

	line = "0 0 10 10 0 0 10 10 0 0 0 0 0 0 0 10 10 0 0";
	n = ft_strlen(line);
	printf("El número de caracteres es: %d\n", n);
	n = ft_count_numbers(line);
	printf("El numero numeros es: %d\n", n);
	//check
	i = 0;
	numbers = ft_take_numbers(line);//error
	while(i < n)
	{
		printf("Los números en la linea son: %s\n", numbers[i]);
		i++;
	}
}
