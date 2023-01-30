/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mag_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouaamm <moouaamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 15:49:27 by moouaamm          #+#    #+#             */
/*   Updated: 2023/01/30 18:45:41 by moouaamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	errorf(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	check_int(char **str)
{
	int		i;
	long	d;

	i = -1;
	while (str[++i])
	{
		d = ft_atoi(str[i]);
		if (d > 2147483647 || d < -2147483648)
			return (0);
	}
	return (1);
}

int	is_empty(t_list *a)
{
	if (a == NULL)
		return (1);
	return (0);
}

void	pop_ele(t_list **a)
{
	t_list	*tmp;

	if (!(*a))
		return ;
	tmp = (*a);
	(*a) = (*a)->next;
	free (tmp);
	tmp = NULL;
}

void	free_stack(t_list **a)
{
	while (is_empty(*a) == 0)
		pop_ele(a);
}
