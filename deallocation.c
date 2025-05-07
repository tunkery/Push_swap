/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deallocation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolcay <bolcay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 10:42:51 by bolcay            #+#    #+#             */
/*   Updated: 2025/02/05 10:43:33 by bolcay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	deallocate_both_stacks(t_stack **a, t_stack **b)
{
	t_stack	*curr;
	t_stack	*temp;

	if (a == NULL || *a == NULL)
		return ;
	curr = *a;
	while (curr)
	{
		temp = curr;
		curr = curr->next;
		free (temp);
	}
	*a = NULL;
	if (b == NULL || *b == NULL)
		return ;
	curr = *b;
	while (curr)
	{
		temp = curr;
		curr = curr->next;
		free (temp);
	}
	*b = NULL;
}

void	deallocate_stack(t_stack **tail)
{
	t_stack	*curr;
	t_stack	*temp;

	if (tail == NULL || *tail == NULL)
		return ;
	curr = *tail;
	while (curr)
	{
		temp = curr;
		curr = curr->next;
		free (temp);
	}
	*tail = NULL;
}

void	deallocate_array(char **str)
{
	int	i;

	if (str == NULL || *str == NULL)
		return ;
	i = 0;
	while (str[i])
		free (str[i++]);
	free (str);
}
