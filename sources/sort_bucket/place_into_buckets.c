/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   place_into_buckets.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/17 14:02:18 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2023/03/02 13:14:39 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	place_into_buckets(t_push_swap *p_s)
/* Establish number of buckets
Find range of stack_a
Find range of bucket */
{
	int	i;

	if (p_s->n > 5 && p_s->n <= 40)
		p_s->bucket->n_buckets = 5;
	if (p_s->n > 40 && p_s->n <= 100)
		p_s->bucket->n_buckets = 10;
	p_s->range = p_s->max_index;
	p_s->bucket->bucket_size = p_s->range / p_s->bucket->n_buckets + 1;
	p_s->bucket->min_bucket = 0;
	p_s->bucket->max_bucket = p_s->min_index + p_s->bucket->bucket_size;
	p_s->bucket->min_bkt_tmp = p_s->min_index;
	p_s->bucket->max_bkt_tmp = p_s->min_index + p_s->bucket->bucket_size;
	i = 0;
	while (i <= p_s->bucket->n_buckets)
	{
		compare_first_last_distance(p_s);
		p_s->bucket->min_bkt_tmp = p_s->bucket->min_bkt_tmp
			+ p_s->bucket->bucket_size;
		p_s->bucket->max_bkt_tmp = p_s->bucket->max_bkt_tmp
			+ p_s->bucket->bucket_size;
		i++;
	}
}

void	compare_first_last_distance(t_push_swap *push_swap)
{	
	int		hold_first;
	int		hold_last;

	while (get_first_in_bucket(push_swap) >= 0)
	{
		hold_first = get_first_in_bucket(push_swap);
		hold_last = get_last_in_bucket(push_swap);
		if (hold_first <= hold_last)
			push_hold_first(push_swap, hold_first);
		else if (hold_first > hold_last)
			push_hold_last(push_swap, hold_last);
	}
}
