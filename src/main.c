/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belam <belam@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 16:57:26 by belam             #+#    #+#             */
/*   Updated: 2026/07/13 22:00:02 by belam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

typedef struct Node 
{
	int			data;
	struct Node	*next;
} Node;

typedef struct 
{
	Node	*head;
	int		size;
} Stack;


void	print_stack(Stack stack)
{
	int	data;
	Node *travel_ptr;

	if (stack.head)
	{
		travel_ptr = stack.head;
		printf("%d\n", travel_ptr->data);
	
		while (travel_ptr->next)
		{
			travel_ptr = travel_ptr->next;
			printf("|\n");
			printf("%d\n", travel_ptr->data);
		}
	}
}


int	main(void)
{
	Node node1 = {.data = 1, .next = NULL};
	Node node2 = {.data = 2, .next = &node1};
	Node node3 = {.data = 3, .next = &node2};
	Node node4 = {.data = 5, .next = &node3};
	Node node5 = {.data = 8, .next = &node4};
	
	Stack stack = {.head = &node5, .size = 5};

	print_stack(stack);


	return (0);
}


