/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkarcevs <gkarcevs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 16:05:19 by girts             #+#    #+#             */
/*   Updated: 2024/08/24 13:09:08 by gkarcevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_three(t_list **list)
{
	t_list	*top;
	t_list	*middle;
	t_list	*bottom;

	if (is_sorted(*list))
		return (1);
	top = *list;
	middle = top->next;
	bottom = middle->next;
	if (top->content > middle->content)
	{
		if (middle->content > bottom->content)
		{
			sa(list);
			rra(list);
			return (1);
		}
		else if (bottom->content > top->content)
		{
			sa(list);
			return (1);
		}
		else if (bottom->content < top->content)
		{
			ra(list);
			return (1);
		}
	}
	else if (top->content < middle->content)
	{
		if (bottom->content > top->content)
		{
			sa(list);
			ra(list);
			return (1);
		}
		else if (bottom->content < top->content)
		{
			rra(list);
			return (1);
		}
	}
	return (0);
}

int	find_min_position(t_list *lst)
{
	int		min;
	int		pos;
	int		min_pos;
	t_list	*current;

	min = lst->content;
	pos = 0;
	min_pos = 0;
	current = lst;
	while (current)
	{
		if (current->content < min)
		{
			min = current->content;
			min_pos = pos;
		}
		current = current->next;
		pos++;
	}
	return (min_pos);
}

void	rotate_to_top(t_list **lst, int pos)
{
	while (pos > 0)
	{
		ra(lst);
		pos--;
	}
}

void	sort_four(t_list **a, t_list **b)
{
	int	min_pos;

	min_pos = find_min_position(*a);
	rotate_to_top(a, min_pos);
	pb(a, b);
	sort_three(a);
	pa(a, b);
}

void	sort_five(t_list **a, t_list **b)
{
	int	min_pos;

	min_pos = find_min_position(*a);
	rotate_to_top(a, min_pos);
	pb(a, b);
	min_pos = find_min_position(*a);
	rotate_to_top(a, min_pos);
	pb(a, b);
	sort_three(a);
	pa(a, b);
	pa(a, b);
}

int	sort_small(t_list **a, t_list **b, int size)
{
	if (size == 2)
	{
		sa(a);
		return (1);
	}
	if (size == 3)
		sort_three(a);
	if (size == 4)
		sort_four(a, b);
	if (size == 5)
		sort_five(a, b);
	return (0);
}
