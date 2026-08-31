/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_target.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belam <belam@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 12:37:08 by belam             #+#    #+#             */
/*   Updated: 2026/08/30 15:27:20 by belam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// set closest smaller node to NULL because stack may NOT have smaller node
static t_node	*get_closest_smaller_node(t_stack *stack, int num)
{
	t_node	*closest_smaller_node;
	t_node	*traverser;

	closest_smaller_node = NULL;
	traverser = stack->head;
	while (traverser)
	{
		if (traverser->data < num)
		{
			if (closest_smaller_node == NULL)
				closest_smaller_node = traverser;
			else
			{
				if (traverser->data > closest_smaller_node->data)
					closest_smaller_node = traverser;
			}
		}
		traverser = traverser->next;
	}
	return (closest_smaller_node);
}

static t_node	*get_closest_larger_node(t_stack *stack, int num)
{
	t_node	*closest_larger_node;
	t_node	*traverser;

	closest_larger_node = NULL;
	traverser = stack->head;
	while (traverser)
	{
		if (traverser->data > num)
		{
			if (closest_larger_node == NULL)
				closest_larger_node = traverser;
			else
			{
				if (traverser->data < closest_larger_node->data)
					closest_larger_node = traverser;
			}
		}
		traverser = traverser->next;
	}
	return (closest_larger_node);
}

t_node	*ft_max_node(t_stack *stack)
{
	t_node	*max_node;
	t_node	*traverser;

	if (stack->head == NULL)
		return (NULL);
	max_node = stack->head;
	traverser = stack->head->next;
	while (traverser)
	{
		if (traverser->data > max_node->data)
			max_node = traverser;
		traverser = traverser->next;
	}
	return (max_node);
}

t_node	*ft_min_node(t_stack *stack)
{
	t_node	*min_node;
	t_node	*traverser;

	if (stack->head == NULL)
		return (NULL);
	min_node = stack->head;
	traverser = stack->head->next;
	while (traverser)
	{
		if (traverser->data < min_node->data)
			min_node = traverser;
		traverser = traverser->next;
	}
	return (min_node);
}

void	assign_target(t_stack *cur_stack, t_stack *target_stack, int smaller)
{
	t_node	*traverser;
	t_node	*target;

	traverser = cur_stack->head;
	while (traverser)
	{
		if (smaller)
		{
			target = get_closest_smaller_node(target_stack, traverser->data);
			if (target == NULL)
				target = ft_max_node(target_stack);
		}
		else
		{
			target = get_closest_larger_node(target_stack, traverser->data);
			if (target == NULL)
				target = ft_min_node(target_stack);
		}
		traverser->target = target;
		traverser = traverser->next;
	}
}
