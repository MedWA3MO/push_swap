/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouaamm <moouaamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 03:48:49 by moouaamm          #+#    #+#             */
/*   Updated: 2023/01/25 22:47:12 by moouaamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	rra(t_list **a, int bp)
{
	t_list	*last;
	int		size;

	if (!a || !(*a))
		return ;
	size = ft_lstsize(*a) - 1;
	last = ft_lstlast(*a);
	if (last->content != (*a)->content)
	{
		last->next = *a;
		*a = last;
		while (size--)
			last = last->next;
		last->next = NULL;
	}
	if (bp)
		write(1, "rra\n", 4);
	return ;
}

void	rrb(t_list **a, int bp)
{
	t_list	*last;
	int		size;

	if (!a || !(*a))
		return ;
	size = ft_lstsize(*a) - 1;
	last = ft_lstlast(*a);
	if (last->content != (*a)->content)
	{
		last->next = *a;
		*a = last;
		while (size--)
			last = last->next;
		last->next = NULL;
	}
	if (bp)
		write(1, "rrb\n", 4);
	return ;
}

void	rrr(t_list **a, t_list **b, int bp)
{
	rra(a, 0);
	rrb(b, 0);
	if (bp)
		write(1, "rrr\n", 4);
	return ;
}
