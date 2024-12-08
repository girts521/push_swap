/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkarcevs <gkarcevs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 11:19:34 by girts             #+#    #+#             */
/*   Updated: 2024/08/24 13:32:12 by gkarcevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//  If there are 2 numbers, swap the first 2 elements at the top of the stack a.
void	sa(t_list **a)
{
	t_list	*head;
	t_list	*new_head;

	ft_printf("sa\n");
	if (*a && (*a)->next)
	{
		head = *a;
		new_head = head->next;
		head->next = new_head->next;
		new_head->next = head;
		*a = new_head;
	}
}

// If there are 2 numbers, swap the first 2 elements at the top of the stack b.
void	sb(t_list **b)
{
	ft_printf("sb\n");
	sa(b);
}

// sa and sb at the same time. 
void	ss(t_list **a, t_list **b)
{
	ft_printf("ss\n");
	sa(a);
	sa(b);
}

//  If b is not empty it takes the first element on top of b and puts it on a.
void	pa(t_list **a, t_list **b)
{
	t_list	*head;

	ft_printf("pa\n");
	if (*b)
	{
		head = ft_pop(b);
		ft_lstadd_front(a, head);
	}
}

//  If a is not empty, it takes the first element on top of a and puts it on b.
void	pb(t_list **a, t_list **b)
{
	t_list	*head;

	ft_printf("pb\n");
	if (*a)
	{
		head = ft_pop(a);
		ft_lstadd_front(b, head);
	}
}

// Shifts all the elements of the stack a up by one position.
//  The first element becomes the last. 
void	ra(t_list **a)
{
	t_list	*head;

	ft_printf("ra\n");
	head = ft_pop(a);
	ft_lstadd_back(a, head);
}

// Shifts all the elements of the stack b one position upwards.
//  The first element becomes the last one. 
void	rb(t_list **b)
{
	ft_printf("rb\n");
	ra(b);
}

// ra and rb at the same time. 
void	rr(t_list **a, t_list **b)
{
	ft_printf("rr\n");
	ra(a);
	rb(b);
}

// Shifts all elements of the stack down one position. 
// the stack a. The last element becomes the first. 
void	rra(t_list **a)
{
	t_list	*last;

	ft_printf("rra\n");
	last = remove_last(a);
	ft_lstadd_front(a, last);
}

// Shifts all the elements of the stack b one position downwards.
// the stack b. The last element becomes the first. 
void	rrb(t_list **b)
{
	ft_printf("rrb\n");
	rra(b);
}

// rra and rrb at the same time.
void	rrr(t_list **a, t_list **b)
{
	ft_printf("rrr\n");
	rra(a);
	rrb(b);
}
