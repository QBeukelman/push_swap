/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: qbeukelm <qbeukelm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/01 11:20:52 by qbeukelm      #+#    #+#                 */
/*   Updated: 2023/03/02 12:11:48 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_stack	*stack_new(int content)
{
	t_stack		*node;

	node = malloc(sizeof(t_stack));
	if (node == NULL)
		return (NULL);
	node->next = 0;
	node->prev = 0;
	node->content = content;
	return (node);
}

t_stack	*stack_last(t_stack *lst)
{
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	stack_add_back(t_stack **lst, t_stack *new_list)
{
	t_stack		*last;

	if (*lst == NULL)
	{
		*lst = new_list;
		return ;
	}
	last = stack_last(*lst);
	last->next = new_list;
	new_list->prev = last;
}

void	stack_clear(t_stack **lst)
{
	t_stack		*temp;

	while (*lst)
	{
		temp = (*lst)->next;
		free (*lst);
		*lst = temp;
	}
	*lst = 0;
}

int	ft_stack_size(t_stack *lst)
{
	size_t	count;

	count = 0;
	while (lst != NULL)
	{
		lst = lst -> next;
		count++;
	}
	return (count);
}
