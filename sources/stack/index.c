/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   index.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/02 12:51:28 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2023/03/03 12:50:23 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	index_stack(t_push_swap *push_swap)
/* Place the relative order of the node, based on its value, as an integer,
starting at 0, into the stack being indexed. */
{
	t_stack		*stack_a;
	int			min_value;
	int			index_value;
	int			i;

	stack_a = push_swap->a;
	min_value = INT_MAX;
	index_value = 0;
	i = 0;
	while (i < push_swap->n)
	{
		stack_a = find_min_value(push_swap);
		stack_a->index = i;
		stack_a->index_bin = ft_itob(i);
		i++;
	}
}

t_stack	*find_min_value(t_push_swap *push_swap)
/* Returns the node with the lowest value */
{
	t_stack		*stack_a;
	int			min_value;

	stack_a = push_swap->a;
	min_value = INT_MAX;
	while (stack_a)
	{
		if (stack_a->content < min_value && stack_a->index == -1)
			min_value = stack_a->content;
		stack_a = stack_a->next;
	}
	stack_a = push_swap->a;
	while (stack_a)
	{
		if (stack_a->content == min_value)
			return (stack_a);
		stack_a = stack_a->next;
	}
	return (NULL);
}

char	*ft_itob(int i)
/* Convert int into binary char array, representd in 32 bits */
{
	char	*bits;
	int		bits_index;

	bits_index = 31;
	bits = (char *) malloc((33) * sizeof(char));
	if (bits == NULL)
	{
		free (bits);
		return (NULL);
	}
	ft_memset(bits, '0', 32);
	while (i > 0)
	{
		bits[bits_index--] = (i & 1) + '0';
		i = (i >> 1);
	}
	return (bits);
}

int	get_longest_binary(t_push_swap *push_swap)
/* Returns the how many significant bits occur in the 32 bit binary string
i = 2 = 00000000000000000000000000000010
return = 1, the last significant bit starting from the back occures in
position 1  */
{
	int		longest;
	int		max_index;
	int		i;
	char	*bin;

	longest = 0;
	max_index = ft_get_max_index(&push_swap->a);
	bin = ft_itob(max_index);
	i = 31;
	longest = 31;
	while (bin[i])
	{
		if (bin[i] == '1')
			longest = i;
		i--;
	}
	free (bin);
	return (31 - longest);
}
