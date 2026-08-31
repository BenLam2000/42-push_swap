/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_cheapest_op.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belam <belam@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 13:29:05 by belam             #+#    #+#             */
/*   Updated: 2026/08/30 14:52:14 by belam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

static void	update_ops_dir_count(t_op_count *cur_op_count,\
	t_op_count *target_op_count, t_ops *ops)
{
	ft_strlcpy(ops->op1.dir, cur_op_count->dir, 3);
	ops->op1.count = cur_op_count->count;
	ft_strlcpy(ops->op2.dir, target_op_count->dir, 3);
	ops->op2.count = target_op_count->count;
}

static unsigned int	rot_to_ops_count(t_op_count *cur_op_count,\
	t_op_count *target_op_count)
{
	if (!ft_strcmp(cur_op_count->dir, target_op_count->dir))
		return (ft_max(cur_op_count->count, target_op_count->count));
	else
		return (cur_op_count->count + target_op_count->count);
}

static void	get_min_ops(t_stack *cur_stack, t_stack *target_stack, t_ops *ops)
{
	t_op_count		cur_op_count;
	t_op_count		target_op_count;
	unsigned int	ops_count;
	unsigned int	min_ops;
	t_node			*traverser;

	min_ops = -1;
	traverser = cur_stack->head;
	while (traverser)
	{
		cur_op_count = min_op(cur_stack, traverser->index, 0);
		target_op_count = min_op(target_stack, traverser->target->index, 0);
		ops_count = rot_to_ops_count(&cur_op_count, &target_op_count);
		if (ops_count < min_ops)
		{
			update_ops_dir_count(&cur_op_count, &target_op_count, ops);
			min_ops = ops_count;
			if (ops_count == 0)
				break ;
		}
		traverser = traverser->next;
	}
}

static void	optimize_ops(t_ops *ops)
{
	unsigned int	op1_count;
	unsigned int	op2_count;

	ops->op1.stack_char = ops->cur_stack_char;
	ops->op2.stack_char = ops->target_stack_char;
	if (!ft_strcmp(ops->op1.dir, ops->op2.dir))
	{
		ops->op1.stack_char = 'r';
		if (ops->op1.count > ops->op2.count)
			ops->op2.stack_char = ops->cur_stack_char;
		else
			ops->op2.stack_char = ops->target_stack_char;
		op1_count = ops->op1.count;
		op2_count = ops->op2.count;
		ops->op1.count = ft_min(op1_count, op2_count);
		ops->op2.count = ft_max(op1_count, op2_count) - ops->op1.count;
	}
}

void	calc_cheapest_op(t_stack *cur_stack, t_stack *target_stack, t_ops *ops)
{
	update_stack_index(cur_stack);
	update_stack_index(target_stack);
	get_min_ops(cur_stack, target_stack, ops);
	optimize_ops(ops);
	ft_strlcpy(ops->op1.op, ops->op1.dir, 4);
	ft_append_char(ops->op1.op, ops->op1.stack_char);
	ft_strlcpy(ops->op2.op, ops->op2.dir, 4);
	ft_append_char(ops->op2.op, ops->op2.stack_char);
}
