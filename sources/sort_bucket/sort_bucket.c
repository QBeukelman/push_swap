/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_bucket.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/17 14:02:41 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2023/03/02 13:04:13 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sort_large(t_push_swap *push_swap)
/* Find the largest number in Stack_B 
and move it to the top of Stack_A
Do this for every element in the bucket
Do this for every bucket */
{
	int	incert_success;

	place_into_buckets(push_swap);
	push_swap->max_index_tmp = ft_get_max_index(&push_swap->b);
	incert_success = 1;
	while (incert_success > -1)
	{
		incert_success = incert_largest_number(push_swap);
		push_swap->max_index_tmp = ft_get_max_index(&push_swap->b);
	}
}

int	incert_largest_number(t_push_swap *push_swap)
/* 1. Traverse the list to find position of highest number
2. Get higetst number to bottom - Perform RB for n times
3. Move largest number to A
4. Corect B - Perform RRB for (n -1) times */
{
	int	max_pos;

	max_pos = get_position_of_max(push_swap);
	if (max_pos == 0)
	{
		ft_push(&push_swap->b, &push_swap->a, "pa");
		return (1);
	}
	else if (max_pos > 0)
	{
		incert_largest_n_opperation(push_swap, max_pos);
		return (1);
	}
	else if (max_pos == -1)
		return (-1);
	return (-1);
}

void	incert_largest_n_opperation(t_push_swap *push_swap, int max_pos)
{
	int	i;

	i = 0;
	while (i < max_pos)
	{
		ft_rotate(&push_swap->b, "rb");
		i++;
	}
	ft_push(&push_swap->b, &push_swap->a, "pa");
	i = 0;
	while (i < max_pos)
	{
		ft_r_rotate(&push_swap->b, "rrb");
		i++;
	}
}

int	get_position_of_max(t_push_swap *push_swap)
/* find largest number - within bucket_size */
{
	t_stack		*b_head;
	int			n;
	int			max;

	b_head = push_swap->b;
	n = 0;
	max = INT_MIN;
	while (b_head)
	{
		if (b_head->index > max)
			max = b_head->index;
		if (n == push_swap->bucket->bucket_size)
			return (n);
		if (max == push_swap->max_index_tmp)
			return (n);
		n++;
		b_head = b_head->next;
	}
	return (-1);
}
