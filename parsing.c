/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouaamm <moouaamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 01:09:16 by moouaamm          #+#    #+#             */
/*   Updated: 2023/01/30 18:41:26 by moouaamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_func(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free (str[i]);
		i++;
	}
	free(str);
}

int	is_digit(char **str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if ((str[i][j] == '-' || str[i][j] == '+') && j == 0)
				j++;
			if (str[i][j] < '0' || str[i][j] > '9')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 != '\0' || *s2 != '\0')
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (0);
}

int	is_dup(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[j])
		{
			if (ft_strcmp(str[j], str[i]) == 0 && i != j)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

t_list	*parsing(int ac, char **args)
{
	char	*my_args;
	int		i;
	t_list	*tab;
	t_list	*list;
	char	**av;

	tab = NULL;
	i = -1;
	my_args = ft_strjoin(ac, args, " ");
	av = ft_split(my_args, ' ');
	if (!is_digit(av) || check_int(av) == 0)
		return (free_func(av), errorf(), NULL);
	while (av[++i])
		ft_lstadd_back(&tab, ft_lstnew(ft_atoi(av[i])));
	list = tab;
	while (list)
	{
		if (checdoubles(list->content, tab) == -1)
			return (errorf(), NULL);
		list = list->next;
	}
	free(my_args);
	free_func(av);
	return (tab);
}
