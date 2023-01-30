/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouaamm <moouaamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 16:29:01 by moouaamm          #+#    #+#             */
/*   Updated: 2023/01/25 22:27:30 by moouaamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define BUFFER_SIZE 5
# include "lib/libft.h"

char	*ft_strjoin(int size, char **strs, char *sep);
t_list	*parsing(int ac, char **args);
int		ft_strcmp(char *s1, char *s2);
int		el_exist(int *tab, int k, int a);
void	range_tree(t_list **a);
void	swap_a(t_list **a, int bp);
void	swap_b(t_list **a, int bp);
void	ss(t_list **a, t_list **b, int bp);
void	range_five(t_list **a, t_list **b, int ac);
int		get_max(t_list *a);
void	push_a(t_list **a, t_list **b, int bp);
void	push_b(t_list **b, t_list **a, int bp);
int		is_sorted(t_list *a);
int		check_int(char **str);
int		*listotab(t_list *a);
int		*lis(int *arr, int n, int *max);
void	clear_lis(t_list **a, t_list **b, int *tab, int *k);
int		get_max_lis(int *lis, int n);
void	display_stack(t_list *a);
int		*init_lis(int n);
void	pop_ele(t_list **a);
void	free_stack(t_list **a);
int		get_index(t_list *a, int data);
int		get_min_move(t_list *a, t_list *b);
void	rra(t_list **a, int bp);
void	rrb(t_list **a, int bp);
void	ra(t_list **a, int bp);
void	rb(t_list **a, int bp);
void	rr(t_list **a, t_list **b, int bp);
void	rrr(t_list **a, t_list **b, int bp);
int		get_next(t_list *stack_A, int elem);
int		calc_move(t_list *stak_A, int k);
void	repush_to_a(t_list **a, t_list **b, int min_inB);
void	push_top_ofstack_a(t_list	**a, int data);
void	push_top_ofstack_b(t_list	**b, int data);
int		get_min(t_list *a);
int		get_min_tab(int	*tab, int k);
void	errorf(void);
int		check_int(char **str);
void	make_rrr_rr(t_list **a, t_list **b, int n);
void	make_rrr(t_list **a, t_list **b, int elem_pos);
void	make_rr(t_list **a, t_list **b, int elem_pos);
int		get_max_int(int x, int y);
char	*get_next_line(int fd);
char	*ft_join(char *s1, char *s2);
char	*ft_stjoin(char *s1, char c);
int		checdoubles(int a, t_list *list);

#endif