/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   initialize_struct.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/17 11:37:07 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2023/03/03 12:50:14 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// ===== Initalise Structs =====
t_stack	*create_stack_with_arg(int argc, char **argv)
/* Returns the first node in a doubly linked list, converting
args into integers, without any checks */
{
	int		i;
	int		x;
	t_stack	*current_node;
	t_stack	*root_node;
	t_stack	*new_node;

	i = 1;
	x = ft_atoi(argv[1]);
	current_node = stack_new(x);
	i++;
	root_node = current_node;
	while (i < argc)
	{
		x = ft_atoi(argv[i]);
		new_node = stack_new(x);
		if (new_node == NULL)
			return (0);
		stack_add_back(&current_node, new_node);
		current_node->index = -1;
		current_node = current_node->next;
		i++;
	}
	current_node->index = -1;
	current_node = root_node;
	return (current_node);
}

t_push_swap	*initalise_push_swap(t_stack *stack_a)
/* Returns the struct containing both stacks a and b,
and additional values are also initalised. */
{
	t_push_swap	*push_swap;

	push_swap = malloc(sizeof(t_push_swap));
	if (push_swap == NULL)
	{
		free (push_swap);
		return (NULL);
	}
	push_swap->a = stack_a;
	push_swap->b = NULL;
	push_swap->n = ft_list_length(push_swap->a);
	index_stack(push_swap);
	push_swap->min_index = 0;
	push_swap->max_index = ft_get_max_index(&push_swap->a);
	push_swap->bucket = initalise_bucket(push_swap);
	push_swap->center = (push_swap->max_index / 2);
	return (push_swap);
}

t_bucket	*initalise_bucket(t_push_swap *push_swap)
{
	t_bucket	*bucket;

	bucket = malloc(sizeof(t_bucket));
	if (bucket == NULL)
	{
		free (bucket);
		return (NULL);
	}
	return (bucket);
}

// ===== Initalise Structs Helpers =====
int	ft_list_length(t_stack *stack)
// Returns the number of nodes in the stack
{
	t_stack	*current;
	int		n;

	n = 0;
	current = stack;
	while (current)
	{
		n++;
		current = current->next;
	}
	return (n);
}

int	ft_get_max_index(t_stack **stack_a)
// Returns the highest value of stack_a->index
{
	t_stack		*current;
	int			max;

	current = *stack_a;
	max = INT_MIN;
	while (current)
	{
		if (current->index > max)
			max = current->index;
		current = current->next;
	}
	return (max);
}
