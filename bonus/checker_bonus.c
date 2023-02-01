/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouaamm <moouaamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 18:32:46 by moouaamm          #+#    #+#             */
/*   Updated: 2023/01/31 22:03:57 by moouaamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	do_rule(t_list **stackA, t_list **stackB, char *rule)
{
	if (ft_strcmp(rule, "sa\n") == 0)
		swap_a(stackA, 0);
	else if (ft_strcmp(rule, "sb\n") == 0)
		swap_b(stackB, 0);
	else if (ft_strcmp(rule, "ss\n") == 0)
		ss(stackA, stackB, 0);
	else if (ft_strcmp(rule, "ra\n") == 0)
		ra(stackA, 0);
	else if (ft_strcmp(rule, "rb\n") == 0)
		rb(stackB, 0);
	else if (ft_strcmp(rule, "rr\n") == 0)
		rr(stackA, stackB, 0);
	else if (ft_strcmp(rule, "rra\n") == 0)
		rra(stackA, 0);
	else if (ft_strcmp(rule, "rrb\n") == 0)
		rrb(stackB, 0);
	else if (ft_strcmp(rule, "rrr\n") == 0)
		rrr(stackA, stackB, 0);
	else if (ft_strcmp(rule, "pa\n") == 0)
		push_a(stackA, stackB, 0);
	else if (ft_strcmp(rule, "pb\n") == 0)
		push_b(stackB, stackA, 0);
	else
		errorf();
}

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;
	char	*rule;

	a = parsing(ac, av);
	if (a == NULL || ac < 2)
		return (1);
	rule = get_next_line(0);
	while (rule)
	{
		do_rule(&a, &b, rule);
		free(rule);
		rule = get_next_line(0);
	}
	free(rule);
	if (is_sorted(a) == 1 && ft_lstsize(b) == 0)
		write(1, "\033[0;32mOK\n", 12);
	else
		write(1, "\033[0;31mKO\n", 12);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
