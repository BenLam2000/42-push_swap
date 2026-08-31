/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belam <belam@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 13:35:28 by belam             #+#    #+#             */
/*   Updated: 2026/08/31 17:13:04 by belam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	update_stack_index(t_stack *stack)
{
	t_node	*traverser;

	traverser = NULL;
	if (stack->head)
	{
		stack->head->index = 0;
		traverser = stack->head->next;
	}
	while (traverser)
	{
		traverser->index = traverser->prev->index + 1;
		traverser = traverser->next;
	}
}

unsigned int	index_of_max(t_stack *stack)
{
	t_node	*max_node;

	update_stack_index(stack);
	max_node = ft_max_node(stack);
	return (max_node->index);
}

int	stack_sorted(t_stack *stack)
{
	t_node	*traverser;

	if (stack->size < 2)
		return (0);
	traverser = stack->head;
	while (traverser->next)
	{
		if (traverser->data > traverser->next->data)
			return (0);
		traverser = traverser->next;
	}
	return (1);
}
