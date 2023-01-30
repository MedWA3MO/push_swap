/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouaamm <moouaamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 16:29:01 by moouaamm          #+#    #+#             */
/*   Updated: 2023/01/26 00:53:17 by moouaamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H
# define BUFFER_SIZE 1
# include "../lib/libft.h"

char	*ft_strjoin(int size, char **strs, char *sep);
t_list	*parsing(int ac, char **args);
int		ft_strcmp(char *s1, char *s2);
void	swap_a(t_list **a, int bp);
void	swap_b(t_list **a, int bp);
void	ss(t_list **a, t_list **b, int bp);
int		get_max(t_list *a);
void	push_a(t_list **a, t_list **b, int bp);
void	push_b(t_list **b, t_list **a, int bp);
int		is_sorted(t_list *a);
int		check_int(char **str);
void	pop_ele(t_list **a);
void	free_stack(t_list **a);
void	rra(t_list **a, int bp);
void	rrb(t_list **a, int bp);
void	ra(t_list **a, int bp);
void	rb(t_list **a, int bp);
void	rr(t_list **a, t_list **b, int bp);
void	rrr(t_list **a, t_list **b, int bp);
void	errorf(void);
int		check_int(char **str);
int		get_max_int(int x, int y);
int		checdoubles(int a, t_list *list);
char	*get_next_line(int fd);
char	*ft_join(char *s1, char *s2);
char	*set_line(char *st_v);
char	*skip_line(char *st_v);
char	*read_line(int fd, char *stv);

#endif