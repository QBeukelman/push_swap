/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   is_sorted.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/03 10:34:46 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2023/03/03 10:38:59 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

bool	is_sorted(t_push_swap *push_swap)
{
	t_stack		*stack_a;

	stack_a = push_swap->a;
	while (stack_a->next != NULL)
	{
		if (stack_a->content > stack_a->next->content)
			return (false);
		stack_a = stack_a->next;
	}
	return (true);
}
