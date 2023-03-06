/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: qbeukelm <qbeukelm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/01 11:20:52 by qbeukelm      #+#    #+#                 */
/*   Updated: 2023/03/06 15:31:12 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_stack	*stack_new(int content)
/**
	@brief Creates a new node with the given content and returns a pointer to it.
	@param content The integer value to be stored in the new node.
	@return A pointer to the new node.
*/
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
/**
	@brief Returns a pointer to the last node in a given stack.
	@param lst A pointer to the top node of the stack.
	@return A pointer to the last node in the stack.
*/
{
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	stack_add_back(t_stack **lst, t_stack *new_list)
/**
	@brief Adds a new node to the end of a given stack.
	@param lst A pointer to the top node of the stack.
	@param new_list A pointer to the node that needs to be added at the end of the stack.
*/
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
/**
	@brief Frees the memory allocated to a given stack and all its nodes (elements).
	@param lst A pointer to the top node of the stack.
*/
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
/**
	@brief Returns the number of nodes (elements) in a given stack.
	@param lst A pointer to the top node of the stack.
	@return The number of nodes (elements) in the stack.
*/
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
