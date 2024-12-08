/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkarcevs <gkarcevs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 20:04:39 by girts             #+#    #+#             */
/*   Updated: 2024/08/24 13:29:31 by gkarcevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static void	free_args(char	**args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		if (args[i])
			free(args[i]);
		i++;
	}
	if (args)
		free(args);
}

static int	validate_digits(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && str[i] != '-' && str[i] != '+')
		{
			error();
			return (0);
		}
		if (str[i] == '-' || str[i] == '+')
		{
			i++;
			if (!ft_isdigit(str[i]))
			{
				error();
				return (0);
			}
		}
		i++;
	}
	return (1);
}

static void	check_double_number(int content, t_list *result)
{
	t_list	*current_node;

	if (!result)
		return ;
	current_node = result;
	while (current_node != NULL)
	{
		if (current_node->content == content)
			error();
		current_node = current_node->next;
	}
}

static void	parse_add(char	**args, t_list **result)
{
	int			i;
	t_list		*new_node;
	long long	content;

	i = 0;
	while (args[i])
	{
		if (validate_digits(args[i]))
		{
			content = ft_atoi(args[i]);
			if (content > INT_MAX || content < INT_MIN)
				error();
			check_double_number((int)content, *result);
			new_node = ft_lstnew(content, "0000000000000000");
			ft_lstadd_back(result, new_node);
		}
		i++;
	}
}

static void	do_nothing(char *binary)
{
	(void)binary;
}

static void	parse_args(int argc, char **argv, t_list **a)
{
	char	**args;
	int		i;

	i = 1;
	while (i < argc)
	{
		args = ft_split(argv[i], ' ');
		if (!args)
			error();
		parse_add(args, a);
		free_args(args);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	int		size;

	a = NULL;
	b = NULL;
	if (argc < 2)
		error();
	parse_args(argc, argv, &a);
	if (a == NULL)
		return (0);
	if (is_sorted(a))
		return (1);
	size = ft_lstsize(a);
	if (size <= 5)
		sort_small(&a, &b, size);
	else
		radix_sort(&a, &b);
	ft_lstclear(&a, do_nothing);
	ft_lstclear(&b, do_nothing);
	return (1);
}
