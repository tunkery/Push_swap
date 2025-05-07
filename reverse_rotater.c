/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotater.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolcay <bolcay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 17:04:31 by bolcay            #+#    #+#             */
/*   Updated: 2025/01/31 14:40:39 by bolcay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotater(t_stack **tail)
{
	t_stack	*last;
	t_stack	*prev;

	if (*tail == NULL || (*tail)->next == NULL)
		return ;
	prev = NULL;
	last = *tail;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *tail;
	*tail = last;
}

void	reverse_rotate_a(t_stack **a)
{
	reverse_rotater(a);
	write (1, "rra\n", 4);
}

void	reverse_rotate_b(t_stack **b)
{
	reverse_rotater(b);
	write (1, "rrb\n", 4);
}

void	reverse_rotate_both(t_stack **a, t_stack **b)
{
	reverse_rotater(a);
	reverse_rotater(b);
	write (1, "rrr\n", 4);
}
