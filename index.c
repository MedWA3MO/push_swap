/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouaamm <moouaamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 18:35:34 by moouaamm          #+#    #+#             */
/*   Updated: 2023/01/22 22:09:51 by moouaamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_index(t_list *a, int data)
{
	int	index;

	index = 0;
	while (a)
	{
		if (a->content == data)
			return (index);
		index++;
		a = a->next;
	}
	return (-1);
}

void	push_b(t_list **b, t_list **a, int bp)
{
	t_list	*tmp;

	tmp = *a;
	if (!*a || !a)
		return ;
	ft_lstadd_front(b, ft_lstnew((*a)->content));
	*a = (*a)->next;
	free(tmp);
	tmp = NULL;
	if (bp)
		write(1, "pb\n", 3);
}

void	ra(t_list **a, int bp)
{
	t_list	*tmp;

	if (!a || !(*a))
		return ;
	tmp = (*a);
	(*a) = (*a)->next;
	tmp->next = NULL;
	ft_lstadd_back(a, tmp);
	if (bp)
		write(1, "ra\n", 3);
}

void	rb(t_list **a, int bp)
{
	t_list	*tmp;

	if (!a || !(*a))
		return ;
	tmp = (*a);
	(*a) = (*a)->next;
	tmp->next = NULL;
	ft_lstadd_back(a, tmp);
	if (bp)
		write(1, "rb\n", 3);
}

void	rr(t_list **a, t_list **b, int bp)
{
	ra(a, 0);
	rb(b, 0);
	if (bp)
		write(1, "rr\n", 3);
}
