/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   range_tree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouaamm <moouaamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 15:32:42 by moouaamm          #+#    #+#             */
/*   Updated: 2023/01/22 01:19:10 by moouaamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max(t_list *a)
{
	int	max;

	max = a->content;
	while (a)
	{
		if (a->content > max)
			max = a->content;
		a = a->next;
	}
	return (max);
}

void	display_stack(t_list *a)
{
	while (a)
	{
		ft_putnbr(a->content, 1);
		a = a->next;
	}
}

void	range_tree(t_list **a)
{
	if (((*a)->content < (*a)->next->content)
		&& ((*a)->next->content < (*a)->next->next->content))
		return ;
	else if (((*a)->content > (*a)->next->content)
		&& ((*a)->content < (*a)->next->next->content))
		swap_a(a, 1);
	else if (((*a)->content > (*a)->next->content)
		&& ((*a)->next->content > (*a)->next->next->content))
	{
		ra(a, 1);
		swap_a(a, 1);
	}
	else if (((*a)->content < (*a)->next->content)
		&& ((*a)->content > (*a)->next->next->content))
		rra(a, 1);
	else if (((*a)->content > (*a)->next->content)
		&& ((*a)->next->content < (*a)->next->next->content))
		ra(a, 1);
	else if (((*a)->content < (*a)->next->content)
		&& ((*a)->next->content > (*a)->next->next->content))
	{
		rra(a, 1);
		swap_a(a, 1);
	}
}

void	range_five(t_list **a, t_list **b, int ac)
{
	int	max;
	int	i;

	i = 3;
	while (i < ac)
	{
		max = get_max(*a);
		push_top_ofstack_a(a, max);
		push_b(b, a, 1);
		i++;
	}
	range_tree(a);
	i = 3;
	while (i < ac)
	{
		push_a(a, b, 1);
		ra(a, 1);
		i++;
	}
}
