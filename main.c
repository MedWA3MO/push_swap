/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouaamm <moouaamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 17:56:43 by moouaamm          #+#    #+#             */
/*   Updated: 2023/01/31 21:50:02 by moouaamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	el_exist(int *tab, int k, int a)
{
	int	i;

	i = 0;
	while (i < a)
	{
		if (tab[i] == k)
			return (1);
		i++;
	}
	return (0);
}

void	clear_lis(t_list **a, t_list **b, int *tab, int *tabsize)
{
	t_list	*tmp;

	tmp = *a;
	while ((ft_lstsize(*a) != *tabsize) && tmp)
	{
		if (el_exist(tab, tmp->content, *tabsize) == 0)
		{
			push_top_ofstack_a(a, tmp->content);
			push_b(b, a, 1);
		}
		tmp = tmp->next;
	}
}

void	push_swap(t_list **a, t_list **b)
{
	while (ft_lstsize(*b) != 0)
		repush_to_a(a, b, get_min_move(*a, *b));
	push_top_ofstack_a(a, get_min(*a));
}

int	main(int ac, char **arg)
{
	t_list	*a;
	t_list	*b;
	int		k;
	int		i;
	int		*tab;

	a = parsing(ac, arg);
	if (a == NULL || ac < 2)
		return (0);
	i = ft_lstsize(a);
	if ((is_sorted(a) == 1))
		return (free_stack(&a), 0);
	if (i == 3)
		return (range_tree(&a), free_stack(&a), 0);
	if (i == 5 || i == 4)
		return (range_five(&a, &b, i), free_stack(&a), 0);
	tab = listotab(a);
	tab = lis(tab, i, &k);
	clear_lis(&a, &b, tab, &k);
	free(tab);
	push_swap(&a, &b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
