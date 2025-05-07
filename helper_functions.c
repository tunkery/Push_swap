/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolcay <bolcay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 18:13:04 by bolcay            #+#    #+#             */
/*   Updated: 2025/02/05 10:45:21 by bolcay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*locate_smallest_element(t_stack *node)
{
	t_stack	*smallest;
	t_stack	*curr;

	if (!node)
		return (NULL);
	smallest = node;
	curr = node->next;
	while (curr)
	{
		if (curr->x < smallest->x)
			smallest = curr;
		curr = curr->next;
	}
	return (smallest);
}

t_stack	*locate_biggest_element(t_stack *node)
{
	t_stack	*biggest;
	t_stack	*curr;

	if (!node)
		return (NULL);
	biggest = node;
	curr = node->next;
	while (curr)
	{
		if (curr->x > biggest->x)
			biggest = curr;
		curr = curr->next;
	}
	return (biggest);
}

int	calculate_moves(t_stack *b, t_stack *target)
{
	t_stack	*temp;
	int		size;
	int		top;

	if (!b || !target)
		return (0);
	temp = b;
	top = 0;
	size = 0;
	while (temp && temp != target)
	{
		top++;
		temp = temp->next;
	}
	temp = b;
	while (temp)
	{
		size++;
		temp = temp->next;
	}
	if (top <= size / 2)
		return (1);
	else
		return (-1);
}

int	lenght_of_stack(t_stack **a)
{
	t_stack	*temp;
	int		size;

	size = 0;
	temp = *a;
	while (temp)
	{
		size++;
		temp = temp->next;
	}
	return (size);
}

int	ft_sqrt(int number)
{
	int	i;

	if (number < 0)
		return (0);
	i = 1;
	while ((i * i <= number) && i <= 46340)
	{
		if ((i * i) == number)
			return (i);
		i++;
	}
	if ((i * i) > number)
		return (i - 1);
	return (0);
}
