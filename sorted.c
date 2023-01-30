/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouaamm <moouaamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 04:19:44 by moouaamm          #+#    #+#             */
/*   Updated: 2023/01/22 22:30:19 by moouaamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_list *a)
{
	int	k;

	if (!a)
		return (1);
	while (a->next)
	{
		k = a->content;
		if (k > a->next->content)
			return (-1);
		a = a->next;
	}
	return (1);
}

void	swap_a(t_list **a, int bp)
{
	int	tmp;

	if ((*a) == NULL || ft_lstsize(*a) == 1)
		return ;
	tmp = (*a)->content;
	(*a)->content = (*a)->next->content;
	(*a)->next->content = tmp;
	if (bp)
		write(1, "sa\n", 3);
}

void	swap_b(t_list **a, int bp)
{
	int	tmp;

	if ((*a) == NULL || ft_lstsize(*a) == 1)
		return ;
	tmp = (*a)->content;
	(*a)->content = (*a)->next->content;
	(*a)->next->content = tmp;
	if (bp)
		write(1, "sb\n", 3);
}

void	ss(t_list **a, t_list **b, int bp)
{
	swap_a(a, 0);
	swap_b(b, 0);
	if (bp)
		write(1, "ss\n", 3);
}

void	push_a(t_list **a, t_list **b, int bp)
{
	t_list	*tmp;

	tmp = *b;
	if (!*b || !b)
		return ;
	ft_lstadd_front(a, ft_lstnew((*b)->content));
	*b = (*b)->next;
	free(tmp);
	tmp = NULL;
	if (bp)
		write(1, "pa\n", 3);
	return ;
}
