/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_radix.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: qbeukelm <qbeukelm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/01 09:10:53 by qbeukelm      #+#    #+#                 */
/*   Updated: 2023/03/02 12:56:31 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sort_radix(t_push_swap *push_swap)
/* Operator function for radix sorting algorythm
1. Get number of significant digites in binar string starting from the back
2. Perform the split_binary operation for the amount of significant bits */
{
	int			most_sig_bit;
	int			current_bit;
	int			i;

	most_sig_bit = get_longest_binary(push_swap);
	current_bit = 31;
	i = 0;
	while (i <= most_sig_bit)
	{
		sort_bits(push_swap, current_bit);
		current_bit--;
		i++;
	}
}

void	sort_bits(t_push_swap *push_swap, int current_bit)
/* Move bits with value 0 to stack_B, and back */
{
	t_stack		*stack_a;
	int			i;
	int			bit_value;

	stack_a = push_swap->a;
	i = 0;
	while (stack_a && i < push_swap->n)
	{
		bit_value = split_binary(push_swap, stack_a, current_bit);
		if (bit_value == 1)
		{
			stack_a = push_swap->a;
			i++;
		}
		else if (bit_value == 0)
		{
			stack_a = push_swap->a;
			i++;
		}
	}
	sort_bits_reverse(push_swap);
}

void	sort_bits_reverse(t_push_swap *push_swap)
{
	t_stack		*stack_b;
	int			len;
	int			i;

	stack_b = push_swap->b;
	i = 0;
	len = ft_stack_size(stack_b);
	while (i <= len)
	{
		ft_push(&push_swap->b, &push_swap->a, "pa");
		i++;
	}
}

int	split_binary(t_push_swap *push_swap, t_stack *stack_a, int bit)
/* Move all nodes where the bit in question is a 1, to stack_b
if bit is 0 push to B
if bit is 1 rotate this node */
{
	if (stack_a->index_bin[bit] == '0')
	{
		ft_push(&push_swap->a, &push_swap->b, "pb");
		return (0);
	}
	else if (stack_a->index_bin[bit] == '1')
	{
		ft_rotate(&push_swap->a, "ra");
		return (1);
	}
	return (-1);
}
