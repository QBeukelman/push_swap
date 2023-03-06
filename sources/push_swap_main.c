/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap_main.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: qbeukelm <qbeukelm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/01 11:20:45 by qbeukelm      #+#    #+#                 */
/*   Updated: 2023/03/06 15:22:24 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

bool	ft_check_args(int argc, char *argv[])
{
	if (argc < 2)
		return (false);
	if (argc == 2)
	{
		ft_check_input(argc, argv);
		return (false);
	}
	if (!ft_check_input(argc, argv))
		return (false);
	return (true);
}

int	main(int argc, char *argv[])
/**
	@brief Main function of a program that sorts integer values using a stack data structure.
	@param argc The number of command-line arguments passed to the program.
	@param argv An array of strings holding the actual arguments passed to the program.
	@return The status code indicating the success or failure of the program execution.
*/
{
	t_stack			*stack_a;
	t_stack			*stack_b;
	t_push_swap		*push_swap;

	if (!ft_check_args(argc, argv))
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
