/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalvez- <fgalvez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 21:16:53 by fgalvez-          #+#    #+#             */
/*   Updated: 2024/11/22 00:44:41 by fgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"

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

int	ft_error(int x, const char *str_1, ...)
{
	va_list		args;
	int			i;
	const char	*str;

	i = 0;
	va_start(args, str_1);
	write(1, "\033[31m", 5);
	str = va_arg(args, const char *);
	ft_strendl(str_1);
	while (str != NULL)
	{
		ft_strendl(str);
		i++;
		str = va_arg(args, const char *);
	}
	va_end(args);
	write(1, "\033[0m", 4);
	return (x);
}
