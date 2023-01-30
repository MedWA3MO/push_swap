/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouaamm <moouaamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 00:35:35 by moouaamm          #+#    #+#             */
/*   Updated: 2023/01/25 21:26:13 by moouaamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_tabs(int *str, int *srt, int *rst)
{
	free(str);
	free(srt);
	free(rst);
}

int	get_max_lis(int *lis, int n)
{
	int	i;
	int	max;

	i = 0;
	max = 0;
	while (i < n)
	{
		if (max <= lis[i])
			max = lis[i];
		i++;
	}
	return (max);
}

int	*init_lis(int n)
{
	int	i;
	int	*lis;

	i = 0;
	lis = (int *) malloc (sizeof(int) * n);
	while (i < n)
	{
		lis[i] = 1;
		i++;
	}
	return (lis);
}

int	*lis_alt(int *lis, int *arr, int *sub, int n)
{
	int	i;
	int	k;
	int	*trl;
	int	max;

	i = 0;
	while (i < n)
	{
		if (max <= lis[i])
		{
			max = lis[i];
			k = i;
		}
		i++;
	}
	trl = (int *) malloc(sizeof(int) * max);
	while (max > 0)
	{
		trl[max - 1] = arr[k];
		k = sub[k];
		max--;
	}
	free_tabs(lis, sub, arr);
	return (trl);
}

int	*lis(int *arr, int n, int *max)
{
	int	*lis;
	int	i;
	int	j;
	int	*sub;

	lis = init_lis(n);
	sub = (int *) malloc (sizeof(int) * n);
	i = 0;
	while (++i < n)
	{
		j = 0;
		while (j < i)
		{
			if (arr[i] > arr[j] && lis[i] < lis[j] + 1)
			{
				lis[i] = lis[j] + 1;
				sub[i] = j;
			}
			j++;
		}
	}
	*max = get_max_lis(lis, n);
	arr = lis_alt(lis, arr, sub, n);
	return (arr);
}
