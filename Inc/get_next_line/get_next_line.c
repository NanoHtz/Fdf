/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalvez- <fgalvez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 19:08:30 by fgalvez-          #+#    #+#             */
/*   Updated: 2024/08/21 18:57:23 by fgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*look_for_end(t_list *list)
{
	if (NULL == list)
		return (NULL);
	while (list->next_bs)
		list = list->next_bs;
	return (list);
}

void	str_cpy(t_list *list, char *str)
{
	int	i;
	int	j;

	j = 0;
	while (list)
	{
		i = 0;
		while (list -> buffer_str[i])
		{
			if (list -> buffer_str[i] == '\n')
			{
				str[j++] = '\n';
				str[j] = '\0';
				return ;
			}
			str[j++] = list -> buffer_str[i++];
		}
		list = list -> next_bs;
	}
	str[j] = '\0';
}

int	len_for_endline(t_list *list)
{
	int	i;
	int	l;

	l = 0;
	while (list)
	{
		i = 0;
		while (list -> buffer_str[i])
		{
			if (list -> buffer_str[i] == '\n')
			{
				++l;
				return (l);
			}
			++i;
			++l;
		}
		list = list -> next_bs;
	}
	return (l);
}

void	make_new_list(t_list **list, int fd)
{
	int		c_read;
	char	*buffer;

	while (!look_for_newline(*list))
	{
		buffer = malloc(BUFFER_SIZE + 1);
		if (buffer == NULL)
			return ;
		c_read = read(fd, buffer, BUFFER_SIZE);
		if (!c_read)
		{
			free(buffer);
			return ;
		}
		buffer[c_read] = '\0';
		add_string_to_list(list, buffer);
	}
}

char	*get_next_line(int fd)
{
	static t_list	*list = NULL;
	char			*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &next_line, 0) < 0)
		return (NULL);
	make_new_list(&list, fd);
	if (list == NULL)
		return (NULL);
	next_line = get_the_line(list);
	prepare_the_recall(&list);
	return (next_line);
}
