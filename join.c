/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouaamm <moouaamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 16:31:34 by moouaamm          #+#    #+#             */
/*   Updated: 2023/01/24 21:17:17 by moouaamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*sec(int size, char **strs, char *sep, char *join)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	while (++i < size)
	{
		j = 0;
		while (strs[i][j])
			join[k++] = strs[i][j++];
		j = 0;
		while (sep[j] && i < size -1)
			join[k++] = sep[j++];
	}
	join[k] = '\0';
	return (join);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		k;
	char	*join;

	k = 0;
	i = 1;
	if (size <= 0)
	{
		join = malloc(sizeof(char));
		join[0] = '\0';
		return (join);
	}
	while (i < size)
		k += ft_strlen(strs[i++]);
	k += (ft_strlen(sep) * (size - 1)) + 1;
	join = malloc(sizeof(char) * k);
	join = sec (size, strs, sep, join);
	return (join);
}

int	checdoubles(int a, t_list *list)
{
	int	j;

	j = 0;
	while (list)
	{
		if (list->content == a)
			j++;
		list = list->next;
	}
	if (j == 2)
		return (-1);
	return (1);
}
