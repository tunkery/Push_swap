/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swapper.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolcay <bolcay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:50:49 by bolcay            #+#    #+#             */
/*   Updated: 2025/02/01 17:42:04 by bolcay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swapper(t_stack **node)
{
	t_stack	*first;
	t_stack	*second;

	if (*node == NULL || (*node)->next == NULL)
		return ;
	first = *node;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*node = second;
}

void	swap_a(t_stack **a)
{
	swapper(a);
	write (1, "sa\n", 3);
}

void	swap_b(t_stack **b)
{
	swapper(b);
	write (1, "sb\n", 3);
}

void	swap_both(t_stack **a, t_stack **b)
{
	swapper(a);
	swapper(b);
	write (1, "ss\n", 3);
}
