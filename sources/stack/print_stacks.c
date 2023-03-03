/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_stacks.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/02 13:06:11 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2023/03/02 13:07:34 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/* 
#include "../../includes/push_swap.h"

void print_stacks(t_stack *stack_a, t_stack *stack_b)
{
	t_stack *current_a = stack_a;
	t_stack *current_b = stack_b;

	printf("\n\nStack A\t\t\tStack B\n");
	printf("--------\t\t--------\n");

	while (current_a || current_b)
	{
		// ===== Values =====
		if (current_a)
		{
			printf("\033[1m%d\033[0m\t\t\t", current_a->content);
		}
		else
			printf("\t\t\t");
		if (current_b)
		{
			printf("\033[1m%d\033[0m\n", current_b->content);
		}
		else
			printf("\n");


		// ===== Index =====
		if (current_a)
		{
			printf("i: %d\t\t\t", current_a->index);
		}
		else
			printf("\t\t\t");
		if (current_b)
		{
			printf("i: %d\n", current_b->index);
		}
		else
			printf("\n");


		// ===== Index Bin =====
		if (current_a)
		{
			printf("b: %s\t\t", current_a->index_bin);
		}
		else
			printf("\t\t\t");
		if (current_b)
		{
			printf("b: %s\n", current_b->index_bin);
		}
		else
			printf("\n");


		// ===== Prev =====
		if (current_a)
		{
			if (current_a->prev)
				printf("p: %p\t", current_a->prev);
			else
				printf("p: %p\t\t\t", current_a->prev);
			
		}
		else
			printf("\t\t\t");
		if (current_b)
		{
			printf("p: %p\n", current_b->prev);
		}
		else
			printf("\n");


		// ===== Current =====
		if (current_a)
		{
			if (current_a)
				printf("c: %p\t", current_a);
			else
				printf("c: %p\t\t\t", current_a);
			
		}
		else
			printf("\t\t\t");
		if (current_b)
		{
			printf("c: %p\n", current_b);
		}
		else
			printf("\n");


		// ===== Next =====
		if (current_a)
		{
			if (current_a->next)
				printf("n: %p\t", current_a->next);
			else
				printf("n: %p\t\t\t", current_a->next);
			current_a = current_a->next;
		}
		else
			printf("\t\t\t");
		if (current_b)
		{
			printf("n: %p\n", current_b->next);
			current_b = current_b->next;
		}
		else
			printf("\n");

		printf("\n");
	}
}
 */ 