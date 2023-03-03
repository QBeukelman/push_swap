/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error_handler.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/02 10:21:29 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2023/03/03 10:59:03 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_error_message(char *msg)
{
	ft_putendl_fd("Error", 1);
	ft_printf("%s\n", msg);
}

// ===== Error Handler =====
bool	ft_check_input(int argc, char **argv)
/* 1. Valid input
2. Duplicate
3. Overflow
!! 4. Memory errors - in init_struct */
{
	if (!ft_check_valid_char(argc, argv))
	{
		ft_error_message("Input contains INVALID CHAR.");
		return (false);
	}
	if (!ft_is_duplicate(argc, argv))
	{
		ft_error_message("Input contains DUPLICATE.");
		return (false);
	}
	if (!ft_int_overflow(argc, argv))
	{
		ft_error_message("Input exceeds LIMIT of INT.");
		return (false);
	}
	return (true);
}

void	free_linked_list(t_stack *stack_a)
{
	t_stack	*current;

	while (stack_a != NULL)
	{
		current = stack_a;
		free (current->index_bin);
		stack_a = stack_a->next;
		free (current);
	}
}
