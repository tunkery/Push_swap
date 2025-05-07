/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotater.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolcay <bolcay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 17:00:00 by bolcay            #+#    #+#             */
/*   Updated: 2025/01/31 16:09:12 by bolcay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotater(t_stack **node)
{
	t_stack	*old_top;
	t_stack	*new_top;
	t_stack	*last;

	if (node == NULL || *node == NULL || (*node)->next == NULL)
		return ;
	old_top = *node;
	new_top = old_top->next;
	last = old_top;
	while (last->next)
		last = last->next;
	last->next = old_top;
	old_top->next = NULL;
	*node = new_top;
}

void	rotate_a(t_stack **a)
{
	rotater(a);
	write (1, "ra\n", 3);
}

void	rotate_b(t_stack **b)
{
	rotater(b);
	write (1, "rb\n", 3);
}

void	rotate_both(t_stack **a, t_stack **b)
{
	rotater(a);
	rotater(b);
	write (1, "rr\n", 3);
}
