/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolcay <bolcay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 22:25:56 by bolcay            #+#    #+#             */
/*   Updated: 2025/02/07 14:52:34 by bolcay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_to_stack(t_stack **node, int value)
{
	t_stack	*new_node;
	t_stack	*curr;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return ;
	new_node->x = value;
	new_node->next = NULL;
	if (*node == NULL)
	{
		*node = new_node;
	}
	else
	{
		curr = *node;
		while (curr->next)
			curr = curr->next;
		curr->next = new_node;
	}
}

void	initialize_the_stack(t_stack **a, char **av, int check)
{
	int		i;
	long	conversion;

	i = 0;
	while (av[i])
	{
		if (av[i][0] == ' ')
			i++;
		if (check_for_valid_entries(av[i]) == -1)
			error_handler(a, av, check);
		conversion = ft_atoi(av[i]);
		if (conversion < INT_MIN || conversion > INT_MAX)
			error_handler(a, av, check);
		if (check_for_duplicates(*a, conversion) == -1)
			error_handler(a, av, check);
		add_to_stack(a, conversion);
		i++;
	}
}
