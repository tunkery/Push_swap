/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolcay <bolcay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 18:12:33 by bolcay            #+#    #+#             */
/*   Updated: 2025/02/05 17:56:48 by bolcay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algorithm(t_stack **a, t_stack **b)
{
	int		i;

	if ((*a) && lenght_of_stack(a) <= 5)
	{
		if (lenght_of_stack(a) == 3)
		{
			three_arguments(a);
			deallocate_stack(a);
		}
		else if (lenght_of_stack(a) == 5 || lenght_of_stack(a) == 2)
			five_arguments(a, b);
	}
	i = ft_sqrt(lenght_of_stack(a));
	while (*a)
	{
		if ((*a)->x <= lenght_of_stack(b))
		{
			push_b(b, a);
			rotate_b(b);
		}
		else if ((*a)->x <= i + lenght_of_stack(b))
			push_b(b, a);
		else
			rotate_a(a);
	}
}

void	push_all_to_a(t_stack **a, t_stack **b)
{
	t_stack	*curr;
	int		i;

	if (!b || !(*b))
		return ;
	while (*b)
	{
		curr = locate_biggest_element(*b);
		i = locate_biggest_element(*b)->x;
		if (calculate_moves(*b, curr) == 1 && lenght_of_stack(b) > 2)
		{
			while ((*b)->x != i)
				rotate_b(b);
		}
		else if (calculate_moves(*b, curr) == -1 && lenght_of_stack(b) > 2)
		{
			while ((*b)->x != i)
				reverse_rotate_b(b);
		}
		push_a(a, b);
		if ((*a)->next && (*a)->x > (*a)->next->x)
			swap_a(a);
	}
}

void	three_arguments(t_stack **node)
{
	int	a;
	int	b;
	int	c;

	if (!(*node))
		return ;
	a = (*node)->x;
	b = (*node)->next->x;
	c = (*node)->next->next->x;
	if (a > b && b < c && a < c)
		swap_a(node);
	else if (a > b && b > c && a > c)
	{
		swap_a(node);
		reverse_rotate_a(node);
	}
	else if (a > b && b < c && a > c)
		rotate_a(node);
	else if (a < b && b > c && a < c)
	{
		swap_a(node);
		rotate_a(node);
	}
	else if (a < b && b > c && a > c)
		reverse_rotate_a(node);
}

void	five_arguments(t_stack **a, t_stack **b)
{
	if (lenght_of_stack(a) == 2)
		two_arguments(a);
	while ((*a) && lenght_of_stack(a) > 3)
	{
		if ((*a)->x == 4 || (*a)->x == 0)
			push_b(b, a);
		if ((*a)->x == 4 || (*a)->x == 0)
			push_b(b, a);
		rotate_a(a);
	}
	three_arguments(a);
	while ((*b) != NULL)
	{
		push_a(a, b);
		if ((*a)->x > (*a)->next->x)
			rotate_a(a);
	}
	if ((*a)->x > (*a)->next->x)
		rotate_a(a);
	deallocate_both_stacks(a, b);
}

void	two_arguments(t_stack **a)
{
	swap_a(a);
	deallocate_stack(a);
	exit(1);
}
