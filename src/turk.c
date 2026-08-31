/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belam <belam@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/22 21:41:36 by belam             #+#    #+#             */
/*   Updated: 2026/08/31 17:20:10 by belam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#define SMALLER 1
#define LARGER 0

// this function returns struct with only direction and count set
// that will bring the node at old_index to new_index in the least
// amount of moves
t_op_count	min_op(t_stack *stack, unsigned int old_index,\
	unsigned int new_index)
{
	int			rot_count;
	int			rev_rot_count;
	t_op_count	op_count;

	if (new_index > old_index)
	{
		rot_count = old_index + (stack->size - new_index);
		rev_rot_count = new_index - old_index;
	}
	else
	{
		rot_count = old_index - new_index;
		rev_rot_count = new_index + (stack->size - old_index);
	}
	if (rot_count < rev_rot_count)
	{
		ft_strlcpy(op_count.dir, "r", 4);
		op_count.count = rot_count;
	}
	else
	{
		ft_strlcpy(op_count.dir, "rr", 4);
		op_count.count = rev_rot_count;
	}
	return (op_count);
}

static void	rot_index(t_stack *stack_a, t_stack *stack_b,\
	unsigned int old_index, unsigned int new_index)
{
	t_op_count	min_ops;

	min_ops = min_op(stack_a, old_index, new_index);
	min_ops.stack_char = 'a';
	ft_strlcpy(min_ops.op, min_ops.dir, 4);
	ft_append_char(min_ops.op, min_ops.stack_char);
	repeat_op(stack_a, stack_b, min_ops.op, min_ops.count);
}

static void	sort_three(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_sorted(stack_a))
		return ;
	rot_index(stack_a, stack_b, index_of_max(stack_a), stack_a->size - 1);
	if (stack_sorted(stack_a))
		return ;
	do_op(stack_a, stack_b, "sa");
}

//	rotate cheapest node and its target
static void	do_cheapest_op(t_stack *stack_a, t_stack *stack_b, t_ops *ops)
{
	char	push_op[3];

	repeat_op(stack_a, stack_b, ops->op1.op, ops->op1.count);
	repeat_op(stack_a, stack_b, ops->op2.op, ops->op2.count);
	ft_strlcpy(push_op, "p", 3);
	ft_append_char(push_op, ops->target_stack_char);
	do_op(stack_a, stack_b, push_op);
}

void	turk(t_stack *stack_a, t_stack *stack_b)
{
	t_ops	ops;

	if (stack_a->size > 3)
	{
		repeat_op(stack_a, stack_b, "pb", 2);
		ops.cur_stack_char = 'a';
		ops.target_stack_char = 'b';
		while (stack_a->size > 3)
		{
			assign_target(stack_a, stack_b, SMALLER);
			calc_cheapest_op(stack_a, stack_b, &ops);
			do_cheapest_op(stack_a, stack_b, &ops);
		}
	}
	sort_three(stack_a, stack_b);
	ops.cur_stack_char = 'b';
	ops.target_stack_char = 'a';
	while (stack_b->size > 0)
	{
		assign_target(stack_b, stack_a, LARGER);
		calc_cheapest_op(stack_b, stack_a, &ops);
		do_cheapest_op(stack_a, stack_b, &ops);
	}
	if (!stack_sorted(stack_a))
		rot_index(stack_a, stack_b, index_of_max(stack_a), stack_a->size - 1);
}
