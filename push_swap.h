/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolcay <bolcay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 15:19:43 by bolcay            #+#    #+#             */
/*   Updated: 2025/02/05 17:55:58 by bolcay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_stack
{
	int				x;
	struct s_stack	*next;
}	t_stack;

// Push operators
void	push_a(t_stack **a, t_stack **b);
void	push_b(t_stack **b, t_stack **a);
// Swap operators
void	swap_a(t_stack **a);
void	swap_b(t_stack **b);
void	swap_both(t_stack **a, t_stack **b);
// Rotate operators
void	rotate_a(t_stack **a);
void	rotate_b(t_stack **b);
void	rotate_both(t_stack **a, t_stack **b);
// Reverse rotate operators
void	reverse_rotate_a(t_stack **a);
void	reverse_rotate_b(t_stack **b);
void	reverse_rotate_both(t_stack **a, t_stack **b);
// Stack creation
void	add_to_stack(t_stack **node, int value);
void	initialize_the_stack(t_stack **a, char **av, int check);
void	organise_the_numbers(t_stack **node, char **av, int check);
// Deallocation functions
void	deallocate_stack(t_stack **tail);
void	deallocate_both_stacks(t_stack **a, t_stack **b);
void	deallocate_array(char **str);
// Error handling
int		check_for_duplicates(t_stack *node, int value);
int		check_for_valid_entries(char *str);
void	error_handler(t_stack **node, char **av, int check);
int		is_ordered(t_stack *node);
// Helper functions
long	ft_atoi(const char *str);
char	**ft_split(char const *s, char c);
int		ft_sqrt(int number);
// Stack functions
t_stack	*locate_biggest_element(t_stack *node);
t_stack	*locate_smallest_element(t_stack *node);
int		lenght_of_stack(t_stack **a);
// Algorithm functions
int		calculate_moves(t_stack *b, t_stack *target);
void	algorithm(t_stack **a, t_stack **b);
void	two_arguments(t_stack **a);
void	three_arguments(t_stack **node);
void	five_arguments(t_stack **a, t_stack **b);
void	push_all_to_a(t_stack **a, t_stack **b);

#endif