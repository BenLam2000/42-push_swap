/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belam <belam@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 11:55:56 by belam             #+#    #+#             */
/*   Updated: 2026/08/30 15:08:59 by belam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	do_op(t_stack *stack_a, t_stack *stack_b, char *op)
{
	if ((!ft_strcmp(op, "sa") || !ft_strcmp(op, "ss")) && stack_a->size >= 2)
		swap(stack_a);
	if ((!ft_strcmp(op, "sb") || !ft_strcmp(op, "ss")) && stack_b->size >= 2)
		swap(stack_b);
	if (ft_strcmp(op, "pa") == 0 && stack_b->size)
		push(stack_b, stack_a);
	else if (ft_strcmp(op, "pb") == 0 && stack_a->size)
		push(stack_a, stack_b);
	if ((!ft_strcmp(op, "ra") || !ft_strcmp(op, "rr")) && stack_a->size >= 2)
		rot(stack_a);
	if ((!ft_strcmp(op, "rb") || !ft_strcmp(op, "rr")) && stack_b->size >= 2)
		rot(stack_b);
	if ((!ft_strcmp(op, "rra") || !ft_strcmp(op, "rrr")) && stack_a->size >= 2)
		rev_rot(stack_a);
	if ((!ft_strcmp(op, "rrb") || !ft_strcmp(op, "rrr")) && stack_b->size >= 2)
		rev_rot(stack_b);
	ft_putstr_fd(op, 1);
	ft_putchar_fd('\n', 1);
}

void	repeat_op(t_stack *stack_a, t_stack *stack_b, char *op,\
	unsigned int count)
{
	while (count > 0)
	{
		do_op(stack_a, stack_b, op);
		count--;
	}
}
