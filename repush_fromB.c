/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repush_fromB.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouaamm <moouaamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 03:48:49 by moouaamm          #+#    #+#             */
/*   Updated: 2023/01/27 23:48:44 by moouaamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	push_top_ofstack_b(t_list	**b, int data)
{
	int	size;
	int	index;

	size = ft_lstsize(*b);
	index = get_index(*b, data);
	while (index != 0 && index != size)
	{
		if (index > size / 2)
		{
			rrb(b, 1);
			index++;
		}
		else
		{
			rb(b, 1);
			index--;
		}
	}
}

void	repush_to_a(t_list **a, t_list **b, int min_inB)
{
	t_list	*tmp;
	int		k;

	tmp = *b;
	k = -1;
	while (tmp)
	{
		if (++k == min_inB)
		{
			if ((k > (ft_lstsize(*b) / 2) && get_index(*a, get_next(*a,
							tmp->content)) > (ft_lstsize(*a) / 2)))
				make_rrr(a, b, tmp->content);
			else if ((k <= (ft_lstsize(*b) / 2) && get_index(*a, get_next(*a,
							tmp->content)) <= (ft_lstsize(*a) / 2)))
				make_rr(a, b, tmp->content);
			else
			{
				push_top_ofstack_a(a, get_next(*a, tmp->content));
				push_top_ofstack_b(b, tmp->content);
			}
		}
		tmp = tmp->next;
	}
	push_a(a, b, 1);
}
