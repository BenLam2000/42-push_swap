/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belam <belam@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/22 21:41:36 by belam             #+#    #+#             */
/*   Updated: 2026/08/23 15:27:40 by belam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// set closest smaller node to NULL because stack may NOT have smaller node
t_node	*get_closest_smaller_node(t_stack *stack, int num)
{
	initialize closest smaller number node to NULL
	while (traversing through stack)
		if (this node number smaller than num)
			if (this node number larger than closest smaller number)
				update closest smaller number node to this node	

	t_node	*closest_smaller_node;
	t_node	*traverser;

	closest_smaller_node = NULL;
	traverser = stack->head;
}

// initialize max_node to something because stack MUST have max
t_node	*get_max_node(t_stack *stack)
{
	t_node	*max_node;
	t_node	*traverser;
	
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



void	assign_target_for_a(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*a_traverser;
	t_node	*b_traverser:

	a_traverser = stack_a->head;
	while (a_traverser)
	{
		b_traverser = stack_b->head;
		while (b_traverser)
		{
			// find the node with closest smaller number	
			b_traverser = b_traverser->next;
		}
		a_traverser = a_traverser->next;
	}
}

void turk(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_a->size > 3)
	{
		select_op(stack_a, stack_b, "pb");
		select_op(stack_a, stack_b, "pb");

		assign_target_for_a(stack_a, stack_b);
	}
}
