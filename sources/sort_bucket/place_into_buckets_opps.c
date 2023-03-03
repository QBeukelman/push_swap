/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   place_into_buckets_opps.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/02 13:14:17 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2023/03/02 13:16:10 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// ===== Operations ====
void	push_hold_first(t_push_swap *push_swap, int hold_first)
// Perform RA for (hold_first -1) times
{
	int	i;

	i = 0;
	while (i < hold_first)
	{
		ft_rotate(&push_swap->a, "ra");
		i++;
	}
	ft_push(&push_swap->a, &push_swap->b, "pb");
}

void	push_hold_last(t_push_swap *push_swap, int hold_last)
// Perform RRA for hold_last times
{
	int	i;

	i = 0;
	while (i <= hold_last)
	{
		ft_r_rotate(&push_swap->a, "rra");
		i++;
	}
	ft_push(&push_swap->a, &push_swap->b, "pb");
}

// ===== Query =====
int	get_first_in_bucket(t_push_swap *push_swap)
// Traverse list forwards to find lowest number within the bracket
{
	t_stack		*a_head;
	int			hold_first;

	a_head = push_swap->a;
	hold_first = 0;
	while (a_head)
	{
		if (a_head->index >= push_swap->bucket->min_bkt_tmp
			&& a_head->index < push_swap->bucket->max_bkt_tmp)
			return (hold_first);
		hold_first++;
		a_head = a_head->next;
	}
	return (-1);
}

int	get_last_in_bucket(t_push_swap *push_swap)
// Traverse list backwards to find lowest number within the bracket
{
	t_stack		*a_tail;
	int			hold_last;

	a_tail = stack_last(push_swap->a);
	hold_last = 0;
	while (a_tail)
	{
		if (a_tail->index >= push_swap->bucket->min_bkt_tmp
			&& a_tail->index < push_swap->bucket->max_bkt_tmp)
			return (hold_last);
		hold_last++;
		a_tail = a_tail->prev;
	}
	return (-1);
}
