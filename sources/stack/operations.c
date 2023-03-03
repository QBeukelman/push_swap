/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operations.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/02 13:17:10 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2023/03/02 13:19:54 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_swap(t_stack **stack_a, char *opp)
/* SA
Swap top two nodes of stack_a */
{
	t_stack	*first;
	t_stack	*second;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	first = *stack_a;
	second = first->next;
	first->next = second->next;
	second->next = first;
	second->prev = first->prev;
	first->prev = second;
	if (first->next != NULL)
		first->next->prev = first;
	*stack_a = second;
	ft_printf("%s\n", opp);
}

void	ft_r_rotate(t_stack **stack_a, char *opp)
/* RRA / RRB
RRA - Bottom of A moves to top of A ft_r_rotate(&push_swap->a, "rra")
RRB - Bottom of B moves to top of B ft_r_rotate(&push_swap->b, "rrb")*/
{
	t_stack	*temp;

	if (*stack_a && (*stack_a)->next)
	{
		temp = *stack_a;
		while (temp->next)
			temp = temp->next;
		temp->prev->next = NULL;
		temp->prev = NULL;
		temp->next = *stack_a;
		(*stack_a)->prev = temp;
		*stack_a = temp;
	}
	ft_printf("%s\n", opp);
}

void	ft_rotate(t_stack **stack_a, char *opp)
/* RA / RB
RA - Rotate stack A ft_ra(&push_swap->a);
RB - Rotate stack b ft_ra(&push_swap->b); */
{
	t_stack	*temp;

	if ((*stack_a)->next == NULL)
		return ;
	temp = (*stack_a)->next;
	(*stack_a)->next = NULL;
	stack_add_back(&temp, *stack_a);
	*stack_a = temp;
	ft_printf("%s\n", opp);
}

void	ft_push(t_stack **from, t_stack **to, char *opp)
/* PA / PB
PB - Send top of A to top of B - ft_push(&push_swap->a, &push_swap->b)
PA - Send top of B to top of A - ft_push(&push_swap->b, &push_swap->a) */
{
	t_stack	*tmp;

	if (*from == NULL)
		return ;
	tmp = *from;
	*from = (*from)->next;
	if (*from)
		(*from)->prev = NULL;
	if (*to)
		(*to)->prev = tmp;
	tmp->next = *to;
	*to = tmp;
	(*to)->prev = NULL;
	ft_printf("%s\n", opp);
}
