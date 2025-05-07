/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolcay <bolcay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 17:28:28 by bolcay            #+#    #+#             */
/*   Updated: 2025/02/07 14:59:22 by bolcay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (ac == 1 || (ac == 2 && av[1][0] == ' ' && !av[1][1]))
		return (0);
	if (ac == 2 && av[1][0])
	{
		av = ft_split(av[1], ' ');
		initialize_the_stack(&a, av, 2);
		organise_the_numbers(&a, av, 2);
	}
	else if (av[1][0])
	{
		initialize_the_stack(&a, &av[1], 0);
		organise_the_numbers(&a, av, 0);
	}
	if (is_ordered(a) == 1)
		deallocate_stack(&a);
	algorithm(&a, &b);
	push_all_to_a(&a, &b);
	deallocate_both_stacks(&a, &b);
	return (0);
}
