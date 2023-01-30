/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouaamm <moouaamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 11:10:45 by moouaamm          #+#    #+#             */
/*   Updated: 2023/01/22 22:29:45 by moouaamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_stjoin(char *s1, char c)
{
	char	*str;
	int		i;
	int		j;

	if (!s1)
		s1 = ft_strdup("");
	str = (char *) malloc((ft_strlen(s1) + 2) * sizeof(char));
	if (!str)
		return (0);
	i = 0;
	j = 0;
	while (s1[j])
		str[i++] = s1[j++];
	str[i++] = c;
	str[i] = 0;
	return (str);
}
