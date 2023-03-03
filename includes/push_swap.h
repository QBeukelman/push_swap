/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: qbeukelm <qbeukelm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/01 11:21:22 by qbeukelm      #+#    #+#                 */
/*   Updated: 2023/03/03 10:40:44 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// ===== Libraries =====
# include "libft/includes/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <memory.h>
# include <limits.h>
# include <stdbool.h>

// ===== Struct =====
typedef struct s_stack
{
	struct s_stack	*next;
	struct s_stack	*prev;
	char			*index_bin;
	int				index;
	int				content;
}	t_stack;

typedef struct s_bucket
{
	int			n_buckets;
	int			bucket_size;
	int			min_bucket;
	int			max_bucket;
	int			min_bkt_tmp;
	int			max_bkt_tmp;
}	t_bucket;

typedef struct s_push_swap
{
	t_stack		*a;
	t_stack		*b;
	t_bucket	*bucket;
	int			n;
	int			max_index;
	int			min_index;
	int			max_index_tmp;
	int			range;
	int			center;
}	t_push_swap;

// ===== Initalize Struct =====
t_push_swap	*initalise_push_swap(t_stack *stack_a);
t_stack		*create_stack_with_arg(int argc, char **argv);
t_bucket	*initalise_bucket(t_push_swap *push_swap);
int			ft_list_length(t_stack *stack);
int			ft_get_max_index(t_stack **stack_a);

// ===== Stack =====
t_stack		*stack_new(int content);
t_stack		*stack_last(t_stack *lst);
void		stack_add_back(t_stack **lst, t_stack *new_list);
void		stack_clear(t_stack **lst);
int			ft_stack_size(t_stack *lst);

// ===== Is Sorted =====
bool	is_sorted(t_push_swap *push_swap);

// ===== Print Stacks =====
void		print_stacks(t_stack *stack_a, t_stack *stack_b);

// ===== Operations =====
void		ft_swap(t_stack **stack_a, char *opp);
void		ft_r_rotate(t_stack **stack_a, char *opp);
void		ft_rotate(t_stack **stack_a, char *opp);
void		ft_push(t_stack **from, t_stack **to, char *opp);

// ===== Sort 3 =====
void		sort_three(t_push_swap *push_swap);
void		sort_two(t_push_swap *push_swap);

// ===== Sort 5 =====
void		sort_five(t_push_swap *push_swap);
void		put_first(t_stack *s_a, t_stack *s_b, t_push_swap *push_swap);
void		put_second(t_stack *s_a, t_stack *s_b, t_push_swap *push_swap);
void		put_second_helper(t_push_swap *push_swap);

// ===== Sort Buckets =====
void		sort_large(t_push_swap *push_swap);
int			incert_largest_number(t_push_swap *push_swap);
void		incert_largest_n_opperation(t_push_swap *push_swap, int max_pos);
int			get_position_of_max(t_push_swap *push_swap);

// ===== Sort Radix =====
void		sort_radix(t_push_swap *push_swap);
void		sort_bits(t_push_swap *push_swap, int current_bit);
void		sort_bits_reverse(t_push_swap *push_swap);
int			split_binary(t_push_swap *push_swap, t_stack *stack_a, int bit);

// ===== Index =====
void		index_stack(t_push_swap *push_swap);
t_stack		*find_min_value(t_push_swap *push_swap);
char		*ft_itob(int i);
int			get_longest_binary(t_push_swap *push_swap);

// ===== Place into Buckets =====
void		place_into_buckets(t_push_swap *push_swap);
void		compare_first_last_distance(t_push_swap *push_swap);

// ===== Place into Buckes Opps
void		push_hold_first(t_push_swap *push_swap, int hold_first);
void		push_hold_last(t_push_swap *push_swap, int hold_last);
int			get_first_in_bucket(t_push_swap *push_swap);
int			get_last_in_bucket(t_push_swap *push_swap);

// ===== Error Handler =====
void		ft_error_message(char *msg);
bool		ft_check_input(int argc, char **argv);
void		free_linked_list(t_stack *stack_a);

// ===== Error Checks =====
bool		ft_check_valid_char(int argc, char **argv);
bool		ft_is_valid_char(char *str);
bool		ft_is_duplicate(int argc, char **argv);
int			ft_len_longest(char *s1, char *s2);
bool		ft_int_overflow(int argc, char **argv);

#endif
