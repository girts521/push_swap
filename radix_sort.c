/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkarcevs <gkarcevs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 18:01:33 by girts             #+#    #+#             */
/*   Updated: 2024/08/24 13:50:52 by gkarcevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	copy_list(t_list *original, t_list **copy)
{
	t_list	*new_node;
	t_list	*current_node;

	current_node = original;
	while (current_node != NULL)
	{
		new_node = ft_lstnew(current_node->content, current_node->binary);
		ft_lstadd_back(copy, new_node);
		current_node = current_node->next;
	}
}

void	index_list(t_list **original, t_list **sorted)
{
	t_list	*current_original;
	t_list	*current_sorted;
	int		count;

	current_original = *original;
	while (current_original != NULL)
	{
		count = 0;
		current_sorted = *sorted;
		while (current_sorted != NULL)
		{
			if (current_original->content == current_sorted->content)
				current_original->content = count;
			count++;
			current_sorted = current_sorted->next;
		}
		current_original = current_original->next;
	}
}

char	*num_to_binary(int nbr)
{
	int		nbr_final[16];
	int		i;
	char	*result;
	int		len;
	char	*base;

	base = "01";
	i = 0;
	result = (char *)malloc(17);
	if (!result)
		return (NULL);
	ft_bzero(result, 17);
	while (i < 16)
	{
		nbr_final[i] = nbr % 2;
		nbr = nbr / 2;
		i++;
	}
	len = i;
	i = 0;
	while (i < len)
	{
		result[i] = base[nbr_final[len - 1 - i]];
		i++;
	}
	result[len] = '\0';
	return (result);
}

void	prepare_radix_sort(t_list **a)
{
	t_list	*sorted_list;
	int		size;

	sorted_list = NULL;
	copy_list(*a, &sorted_list);
	size = ft_lstsize(sorted_list) - 1;
	quick_sort(&sorted_list, 0, size);
	index_list(a, &sorted_list);
}

char	**num_to_binary_list(t_list **a)
{
	char	**binary_list;
	t_list	*current_node;
	int		i;
	int		size;

	size = ft_lstsize(*a);
	binary_list = (char **)malloc(sizeof(char *) * (size + 1));
	if (!binary_list)
		return (NULL);
	current_node = *a;
	i = 0;
	while (current_node != NULL)
	{
		binary_list[i] = num_to_binary(current_node->content);
		current_node = current_node->next;
		i++;
	}
	return (binary_list);
}

static void	do_nothing(int content)
{
	(void)content;
}

void	radix_sort(t_list **a, t_list **b)
{
	char	**binary_list;
	int		i;
	int		j;
	t_list	*current_node;
	int		size_a;

	prepare_radix_sort(a);
	binary_list = num_to_binary_list(a);
	i = ft_lstsize(*a);
	current_node = *a;
	i = 0;
	while (current_node != NULL)
	{
		current_node->binary = binary_list[i];
		current_node = current_node->next;
		i++;
	}
	i = 16;
	j = 0;
	current_node = *a;
	size_a = ft_lstsize(*a);
	while (i >= 0)
	{
		j = 0;
		while (j < size_a && !is_sorted(*a))
		{
			if ((*a)->binary[i] == '1')
				ra(a);
			else
				pb(a, b);
			j++;
		}
		while (*b != NULL)
		{
			pa(a, b);
		}
		i--;
	}
	ft_lstiter(*b, do_nothing);
}
