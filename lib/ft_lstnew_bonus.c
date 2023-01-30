/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouaamm <moouaamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 20:46:06 by moouaamm          #+#    #+#             */
/*   Updated: 2023/01/11 17:13:50 by moouaamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

t_list	*ft_lstnew(int content)
{
	t_list	*lis;

	lis = (t_list *) malloc(sizeof(t_list) * 1);
	if (!lis)
		return (NULL);
	lis -> content = content;
	lis -> next = NULL;
	return (lis);
}
