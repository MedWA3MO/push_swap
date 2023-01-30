/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_utils_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouaamm <moouaamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 18:23:29 by moouaamm          #+#    #+#             */
/*   Updated: 2023/01/26 01:28:35 by moouaamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

char	*ft_join(char *s1, char *s2)
{
	char	*join;
	size_t	a;
	size_t	i;

	if (!s1)
		s1 = ft_strdup("");
	if (!s2)
		return (NULL);
	a = ft_strlen(s1);
	i = -1;
	join = (char *) malloc(sizeof(char) * (a + ft_strlen(s2) + 1));
	if (!join)
		return (NULL);
	while (++i < a)
		join[i] = s1[i];
	i = -1;
	while (++i < ft_strlen(s2))
		join[i + a] = s2[i];
	free(s1);
	s1 = NULL;
	join[i + a] = '\0';
	return (join);
}
