/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkarcevs <gkarcevs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 13:30:25 by girts             #+#    #+#             */
/*   Updated: 2024/08/24 13:06:43 by gkarcevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Removes the head from the list and returns it
t_list	*ft_pop(t_list **list)
{
	t_list	*removed;

	if (*list == NULL)
		return (NULL);
	removed = *list;
	*list = (*list)->next;
	removed->next = NULL;
	return (removed);
}

t_list	*remove_last(t_list **list)
{
	t_list	*last_node;
	t_list	*previous_node;

	if (!list)
		return (NULL);
	if (*list == NULL)
		return (*list);
	last_node = *list;
	previous_node = *list;
	while (last_node->next != NULL)
	{
		previous_node = last_node;
		last_node = last_node->next;
	}
	previous_node->next = NULL;
	return (last_node);
}

int	is_sorted(t_list *list)
{
	t_list	*current_node;

	if (!list->next)
		return (1);
	current_node = list;
	while (current_node->next != NULL)
	{
		if (current_node->content > current_node->next->content)
			return (0);
		current_node = current_node->next;
	}
	return (1);
}

t_list	*get_node_at_index(t_list **list, int index, t_list **prev)
{
	t_list	*current_node;
	int		i;

	i = 0;
	current_node = *list;
	while (current_node && i < index)
	{
		if (prev)
			*prev = current_node;
		current_node = current_node->next;
		i++;
	}
	if (i < index)
		return (NULL);
	return (current_node);
}

void	print_list(int content)
{
	ft_printf("num is: %d\n", content);
}
