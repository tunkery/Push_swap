/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pusher.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolcay <bolcay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:39:08 by bolcay            #+#    #+#             */
/*   Updated: 2025/02/05 17:33:05 by bolcay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	pusher(t_stack **main, t_stack **other)
{
	t_stack	*new_node;

	if (!main || !(*main))
		return ;
	new_node = *main;
	*main = (*main)->next;
	if (*other == NULL)
	{
		*other = new_node;
		new_node->next = NULL;
	}
	else
	{
		new_node->next = *other;
		*other = new_node;
	}
}

void	push_a(t_stack **a, t_stack **b)
{
	pusher(b, a);
	write (1, "pa\n", 3);
}

void	push_b(t_stack **b, t_stack **a)
{
	pusher(a, b);
	write (1, "pb\n", 3);
}
