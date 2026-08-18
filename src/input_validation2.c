/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belam <belam@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 12:33:35 by belam             #+#    #+#             */
/*   Updated: 2026/08/18 12:42:50 by belam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	has_duplicate(t_stack *stackptr, int num)
{
	t_node	*traverser;

	traverser = stackptr->head;
	while (traverser)
	{
		if (traverser->data == num)
			return (1);
		traverser = traverser->next;
	}
	return (0);
}

int	is_sorted(t_stack *stackptr)
{
	t_node	*traverser;

	if (stackptr->size < 2)
		return (0);
	traverser = stackptr->head;
	while (traverser->next)
	{
		if (traverser->data > traverser->next->data)
			return (0);
		traverser = traverser->next;
	}
	return (1);
}
