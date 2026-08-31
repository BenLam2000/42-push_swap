/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belam <belam@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 20:03:57 by belam             #+#    #+#             */
/*   Updated: 2026/08/31 17:18:37 by belam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// node1 and node2 are not NULL, checked to have min 2 nodes
// edge case: only 2 nodes, tail will be severed and node3 has no prev
void	swap(t_stack *stack)
{
	t_node	*node1;
	t_node	*node2;
	t_node	*node3;

	node1 = stack->head;
	node2 = stack->head->next;
	node3 = stack->head->next->next;
	stack->head = node2;
	node2->prev = NULL;
	node2->next = node1;
	node1->prev = node2;
	node1->next = node3;
	if (node3)
		node3->prev = node1;
	else
		stack->tail = node1;
}

// check every dereference of t_node for NULL
// check for reassignment of tail node also
// edge cases: from_stack 1->0 nodes, to_stack 0->1 nodes: need to reassign tail
void	push(t_stack *from_stack, t_stack *to_stack)
{
	t_node	*push_node;
	t_node	*from_stack_new_head;
	t_node	*to_stack_old_head;

	push_node = from_stack->head;
	from_stack_new_head = from_stack->head->next;
	to_stack_old_head = to_stack->head;
	from_stack->head = from_stack_new_head;
	if (from_stack->head)
		from_stack->head->prev = NULL;
	else
		from_stack->tail = NULL;
	to_stack->head = push_node;
	push_node->prev = NULL;
	push_node->next = to_stack_old_head;
	if (push_node->next)
		push_node->next->prev = push_node;
	else
		to_stack->tail = push_node;
	(from_stack->size)--;
	(to_stack->size)++;
}

// head and tail must exist since to rot must have >= 2 nodes
void	rot(t_stack *stack)
{
	t_node	*old_head;
	t_node	*old_tail;

	old_head = stack->head;
	old_tail = stack->tail;
	stack->head = stack->head->next;
	stack->head->prev = NULL;
	old_tail->next = old_head;
	old_head->prev = old_tail;
	old_head->next = NULL;
	stack->tail = old_head;
}

// head and tail must exist since to rot must have >= 2 nodes
void	rev_rot(t_stack *stack)
{
	t_node	*old_tail;
	t_node	*old_head;
	t_node	*new_tail;

	old_tail = stack->tail;
	old_head = stack->head;
	new_tail = stack->tail->prev;
	stack->head = old_tail;
	stack->head->prev = NULL;
	stack->head->next = old_head;
	stack->head->next->prev = old_tail;
	new_tail->next = NULL;
	stack->tail = new_tail;
}
