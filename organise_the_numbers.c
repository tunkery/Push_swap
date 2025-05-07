/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   organise_the_numbers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolcay <bolcay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 18:12:45 by bolcay            #+#    #+#             */
/*   Updated: 2025/02/05 17:36:14 by bolcay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atoi(const char *str)
{
	long	i;
	long	check;
	long	result;

	result = 0;
	i = 0;
	check = 1;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			check *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result *= 10;
		result += str[i] - 48;
		i++;
	}
	return (result * check);
}

static int	*create_array(char **av, int size, int check)
{
	int		*array;
	int		i;
	int		j;

	array = malloc(sizeof(int) * (size));
	if (!array)
		return (NULL);
	if (check > 1)
	{
		i = -1;
		j = 0;
	}
	else
	{
		i = 0;
		j = 0;
	}
	while (av[i + 1])
	{
		array[j] = ft_atoi(av[i + 1]);
		i++;
		j++;
	}
	return (array);
}

static void	sort_the_array(int *array, int size, int check)
{
	int	i;
	int	j;
	int	temp;

	if (check > 1)
		size--;
	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j + 1];
				array[j + 1] = array[j];
				array[j] = temp;
			}
			j++;
		}
		i++;
	}
}

static void	assign_values_to_array(t_stack **node, int *array, int size)
{
	t_stack	*curr;
	int		i;

	curr = *node;
	while (curr)
	{
		i = 0;
		while (i < size)
		{
			if (array[i] == curr->x)
			{
				curr->x = i;
				break ;
			}
			i++;
		}
		curr = curr->next;
	}
}

void	organise_the_numbers(t_stack **node, char **av, int check)
{
	int	*array;
	int	size;

	size = lenght_of_stack(node);
	if (check > 1)
		size++;
	array = create_array(av, size, check);
	if (!array)
		return ;
	sort_the_array(array, size, check);
	assign_values_to_array(node, array, size);
	if (check > 1)
		deallocate_array(av);
	free (array);
}
