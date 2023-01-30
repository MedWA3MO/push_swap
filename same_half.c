/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   same_half.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouaamm <moouaamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 22:33:14 by moouaamm          #+#    #+#             */
/*   Updated: 2023/01/24 04:35:06 by moouaamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_top_ofstack_a(t_list	**a, int data)
{
	int	size;
	int	index;

	size = ft_lstsize(*a);
	index = get_index(*a, data);
	while (index != 0 && index != size)
	{
		if (index > size / 2)
		{
			rra(a, 1);
			index++;
		}
		else
		{
			ra(a, 1);
			index--;
		}
	}
}

int	get_max_int(int x, int y)
{
	if (x > y)
		return (x);
	return (y);
}

void	make_rrr(t_list **a, t_list **b, int elem)
{
	while (get_index(*b, elem) != 0 && get_index(*a, get_next(*a, elem)) != 0)
		rrr(a, b, 1);
	while (get_index(*b, elem) != 0)
		rrb(b, 1);
	while (get_index(*a, get_next(*a, elem)) != 0)
		rra(a, 1);
}

void	make_rr(t_list **a, t_list **b, int elem)
{
	while (get_index(*b, elem) != 0 && get_index(*a, get_next(*a, elem)) != 0)
		rr(a, b, 1);
	while (get_index(*b, elem) != 0)
		rb(b, 1);
	while (get_index(*a, get_next(*a, elem)) != 0)
		ra(a, 1);
}
