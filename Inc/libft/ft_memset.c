/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalvez- <fgalvez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 11:25:20 by fgalvez-          #+#    #+#             */
/*   Updated: 2024/03/25 23:43:16 by fgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int x, size_t len)
{
	unsigned char	*aux;

	aux = (unsigned char *) b;
	while (len > 0)
	{
		*aux = (unsigned char) x;
		len--;
		aux++;
	}
	return (b);
}
