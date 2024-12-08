/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: girts521 <girts521@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:32:57 by girts             #+#    #+#             */
/*   Updated: 2024/08/20 12:24:21 by girts521         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf.h"

void	error();
void	sa(t_list **a);
void	sb(t_list **b);
void	ss(t_list **a, t_list **b);
void	pa(t_list **a, t_list **b);
void	pb(t_list **a, t_list **b);
void	ra(t_list **a);
void	rb(t_list **b);
void	rr(t_list **a, t_list **b);
void	rra(t_list **a);
void	rrb(t_list **b);
void	rrr(t_list **a, t_list **b);
int		is_sorted(t_list *list);
int		sort_small(t_list **a, t_list **b, int size);
int		sort_three(t_list **list);
void	sort_five(t_list **a, t_list **b);
void     radix_sort(t_list **a, t_list **b);
t_list	*ft_pop(t_list **list);
t_list	*remove_last(t_list **list);
t_list	*get_node_at_index(t_list **list, int index, t_list **prev);
t_list **quick_sort(t_list **list, int left, int right);
void	print_list(int content);

#endif