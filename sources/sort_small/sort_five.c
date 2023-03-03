/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_five.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/01 18:28:17 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2023/03/02 12:22:28 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sort_five(t_push_swap *push_swap)
/* Push top two elements to s_b
Perform sort three
!! 10 77 2 100 5 = wc: 14 */
{
	t_stack	*s_a;
	t_stack	*s_b;
	int		b_one;
	int		b_two;

	ft_push(&push_swap->a, &push_swap->b, "pb");
	ft_push(&push_swap->a, &push_swap->b, "pb");
	sort_three(push_swap);
	s_a = push_swap->a;
	s_b = push_swap->b;
	b_one = s_b->content;
	b_two = s_b->next->content;
	if (b_one > b_two)
		ft_swap(&push_swap->b, "sb");
	put_first(push_swap->a, push_swap->b, push_swap);
	put_second(push_swap->a, push_swap->b, push_swap);
}

void	put_first(t_stack *s_a, t_stack *s_b, t_push_swap *push_swap)
{
	if (s_a->content > s_b->content)
		ft_push(&push_swap->b, &push_swap->a, "pa");
	else if (s_a->content < s_b->content && s_a->next->content > s_b->content)
	{
		ft_push(&push_swap->b, &push_swap->a, "pa");
		ft_swap(&push_swap->a, "sa");
	}
	else if ((s_a->next->content < s_b->content)
		&& s_a->next->next->content > s_b->content)
	{
		ft_r_rotate(&push_swap->a, "rra");
		ft_push(&push_swap->b, &push_swap->a, "pa");
		ft_r_rotate(&push_swap->a, "rra");
		ft_r_rotate(&push_swap->a, "rra");
	}
	else if (s_a->next->next->content < s_b->content)
	{
		ft_push(&push_swap->b, &push_swap->a, "pa");
		ft_rotate(&push_swap->b, "rb");
	}
}

void	put_second(t_stack *s_a, t_stack *s_b, t_push_swap *push_swap)
{
	if (s_a->content > s_b->content)
		ft_push(&push_swap->b, &push_swap->a, "pa");
	else if (s_a->content < s_b->content && s_a->next->content > s_b->content)
	{
		ft_push(&push_swap->b, &push_swap->a, "pa");
		ft_swap(&push_swap->a, "sa");
	}
	else if (s_a->next->content < s_b->content
		&& s_a->next->next->content > s_b->content)
		put_second_helper(push_swap);
	else if (s_a->next->next->content < s_b->content
		&& s_a->next->next->next->content > s_b->content)
	{
		ft_r_rotate(&push_swap->a, "rra");
		ft_push(&push_swap->b, &push_swap->a, "pa");
		ft_r_rotate(&push_swap->a, "rra");
		ft_r_rotate(&push_swap->a, "rra");
		ft_r_rotate(&push_swap->a, "rra");
	}
	else if (s_a->next->next->next->content < s_b->content)
	{
		ft_push(&push_swap->b, &push_swap->a, "pa");
		ft_rotate(&push_swap->a, "ra");
	}
}

void	put_second_helper(t_push_swap *push_swap)
{
	ft_r_rotate(&push_swap->a, "rra");
	ft_r_rotate(&push_swap->a, "rra");
	ft_push(&push_swap->b, &push_swap->a, "pa");
	ft_r_rotate(&push_swap->a, "rra");
	ft_r_rotate(&push_swap->a, "rra");
}
