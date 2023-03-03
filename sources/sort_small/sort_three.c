/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_three.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/02 12:03:24 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2023/03/03 10:31:35 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sort_three(t_push_swap *push_swap)
/* Compare top to middle, middle to bottom, and bottom to top
Depending on which number is bigger or smaller will affect 
which actions to call */
{
	t_stack	*arr;
	int		a;
	int		b;
	int		c;

	a = push_swap->a->content;
	b = push_swap->a->next->content;
	c = push_swap->a->next->next->content;
	arr = push_swap->a;
	if (a > b && b < c && c > a)
		ft_swap(&push_swap->a, "sa");
	else if (a > b && b > c && c < a)
	{
		ft_swap(&push_swap->a, "sa");
		ft_r_rotate(&push_swap->a, "rra");
	}
	else if (a > b && b < c && c < a)
		ft_rotate(&push_swap->a, "ra");
	else if (a < b && b > c && c > a)
	{
		ft_swap(&push_swap->a, "sa");
		ft_rotate(&push_swap->a, "ra");
	}
	else if (a < b && b > c && c < a)
		ft_r_rotate(&push_swap->a, "rra");
}

void	sort_two(t_push_swap *push_swap)
{
	if (push_swap->a->content > push_swap->a->next->content)
		ft_swap(&push_swap->a, "sa");
}
