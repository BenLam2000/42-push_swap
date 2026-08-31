/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belam <belam@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 13:18:57 by belam             #+#    #+#             */
/*   Updated: 2026/08/31 17:12:06 by belam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h> // malloc, free, exit

typedef struct s_node
{
	int				data;
	unsigned int	index;
	struct s_node	*target;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	t_node	*head;
	t_node	*tail;
	size_t	size;
}	t_stack;

// op needs to be full op, including 'a' or 'b'
typedef struct s_op_count
{
	char			dir[3];
	char			stack_char;
	char			op[4];
	unsigned int	count;
}	t_op_count;

// op1 = cur_stack initially, but may change if optimized
typedef struct s_ops
{
	char		cur_stack_char;
	char		target_stack_char;
	t_op_count	op1;
	t_op_count	op2;
}	t_ops;

// stack utils
void			create_stack(int *num_arr, size_t len, t_stack *stack);
void			update_stack_index(t_stack *stack);
unsigned int	index_of_max(t_stack *stack);
int				stack_sorted(t_stack *stack);
void			free_stack(t_stack *stack);

// input
void			parse_input(int argc, char **argv, t_stack *stack);
void			arr_sorted(int arr[], int len);
void			arr_duplicates(int arr[], int len);

// operations
void			swap(t_stack *stack);
void			push(t_stack *from_stack, t_stack *to_stack);
void			rot(t_stack *stack);
void			rev_rot(t_stack *stack);
void			do_op(t_stack *stack_a, t_stack *stack_b, char *op);
void			repeat_op(t_stack *stack_a, t_stack *stack_b, char *op,\
	unsigned int count);

// turk
t_node			*ft_max_node(t_stack *stack);
t_node			*ft_min_node(t_stack *stack);
t_op_count		min_op(t_stack *stack, unsigned int old_index,\
	unsigned int new_index);
void			assign_target(t_stack *cur_stack, t_stack *target_stack,\
	int smaller);
void			calc_cheapest_op(t_stack *cur_stack, t_stack *target_stack,\
	t_ops *ops);
void			turk(t_stack *stack_a, t_stack *stack_b);

// error
void			ft_error(int exit_code);
#endif
