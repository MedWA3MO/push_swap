/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_mv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouaamm <moouaamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 17:04:14 by moouaamm          #+#    #+#             */
/*   Updated: 2023/01/25 21:26:27 by moouaamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min(t_list *a)
{
	int	min;

	min = a->content;
	while (a)
	{
		if (min > a->content)
			min = a->content;
		a = a->next;
	}
	return (min);
}

int	get_next(t_list *stack_A, int elem)
{
	int	next;

	next = get_max(stack_A);
	if (elem > next)
		return (get_min(stack_A));
	while (stack_A)
	{
		if (elem < stack_A->content && stack_A->content < next)
			next = stack_A->content;
		stack_A = stack_A->next;
	}
	return (next);
}

int	calc_move(t_list *stak_A, int k)
{
	int	size;
	int	indice;
	int	move;

	move = 0;
	size = ft_lstsize(stak_A);
	indice = get_index(stak_A, k);
	while (indice != size && indice != 0)
	{
		if (indice > size / 2)
		{
			indice++;
			move++;
		}
		else
		{
			indice--;
			move++;
		}
	}
	return (move);
}

int	get_min_tab(int	*tab, int k)
{
	int	i;
	int	j;
	int	min;

	i = 0;
	j = i;
	min = tab[i];
	while (i < k)
	{
		if (min > tab[i])
		{
			min = tab[i];
			j = i;
		}
		i++;
	}
	return (j);
}

int	get_min_move(t_list *a, t_list *b)
{
	int		*mvs;
	int		c;
	int		i;
	t_list	*tmp;

	tmp = b;
	i = -1;
	c = ft_lstsize(b);
	mvs = (int *) malloc (sizeof(int) * c);
	while (b)
	{
		if ((get_index(tmp, b->content) > c / 2
				&& get_index(a, get_next(a, b->content)) > (ft_lstsize(a) / 2))
			|| (get_index(tmp, b->content) <= c / 2
				&& get_index(a, get_next(a, b->content)) <= ft_lstsize(a) / 2))
			mvs[++i] = get_max_int(calc_move(tmp, b->content),
					calc_move(a, get_next(a, b->content)));
		else
			mvs[++i] = calc_move(tmp, b->content)
				+ calc_move(a, get_next(a, b->content));
			b = b->next;
	}
	i = get_min_tab(mvs, c);
	free(mvs);
	return (i);
}
