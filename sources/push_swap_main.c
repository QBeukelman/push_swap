/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap_main.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: qbeukelm <qbeukelm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/01 11:20:45 by qbeukelm      #+#    #+#                 */
/*   Updated: 2023/03/03 12:48:02 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack			*stack_a;
	t_stack			*stack_b;
	t_push_swap		*push_swap;

	if (argc <= 2)
		return (EXIT_FAILURE);
	if (!ft_check_input(argc, argv))
		return (EXIT_FAILURE);
	stack_a = create_stack_with_arg(argc, argv);
	push_swap = initalise_push_swap(stack_a);
	if (is_sorted(push_swap))
		return (EXIT_SUCCESS);
	if (push_swap->n == 2)
		sort_two(push_swap);
	else if (push_swap->n == 3)
		sort_three(push_swap);
	else if (push_swap->n > 3 && push_swap->n <= 5)
		sort_five(push_swap);
	else if (push_swap->n > 5 && push_swap->n < 500)
		sort_large(push_swap);
	else if (push_swap->n >= 500)
		sort_radix(push_swap);
	free_linked_list(push_swap->a);
	return (EXIT_SUCCESS);
}

/* 
1. Run checker with void parameters, and several " ", "/" = ERROR.
2. 0 instructions for ordered list.
*/
