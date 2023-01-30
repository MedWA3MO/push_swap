/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_to_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouaamm <moouaamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 20:33:47 by moouaamm          #+#    #+#             */
/*   Updated: 2023/01/11 20:38:26 by moouaamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*listotab(t_list *a)
{
	int	*tab;
	int	n;
	int	i;

	i = 0;
	n = ft_lstsize(a);
	tab = malloc (sizeof(int) * n);
	if (!tab)
		return (NULL);
	while (i < n)
	{
		tab[i] = a->content;
		a = a->next;
		i++;
	}
	return (tab);
}
