/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolcay <bolcay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 17:08:55 by bolcay            #+#    #+#             */
/*   Updated: 2025/02/07 14:58:34 by bolcay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_handler(t_stack **node, char **av, int check)
{
	deallocate_stack(node);
	write (1, "error\n", 6);
	if (check > 1)
		deallocate_array(av);
	exit(1);
}

int	check_for_duplicates(t_stack *node, int value)
{
	if (!node)
		return (0);
	while (node)
	{
		if (node->x == value)
			return (-1);
		node = node->next;
	}
	return (1);
}

int	is_ordered(t_stack *node)
{
	t_stack	*curr;
	int		j;

	if (!node)
		return (0);
	curr = node;
	while (curr->next)
	{
		j = curr->x;
		curr = curr->next;
		if (j > curr->x)
			return (-1);
	}
	return (1);
}

int	check_for_valid_entries(char *str)
{
	int	i;

	i = 0;
	if (!str || !str[0])
		return (-1);
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i] || !(str[i] >= '0' && str[i] <= '9'))
		return (-1);
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (-1);
		i++;
	}
	return (1);
}
