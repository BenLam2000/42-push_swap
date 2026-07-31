/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belam <belam@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 16:57:26 by belam             #+#    #+#             */
/*   Updated: 2026/07/31 15:42:50 by belam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_node 
{
	int					data;
	struct s_node	*next;
} t_node;

typedef struct	s_stack
{
	t_node	*head;
	int		size;
} t_stack;

/*
This function creates a new stack node,
places data in it, then links it to NULL
next node in the linked list will simply override NULL
*/
t_node	*create_node(int data)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->data = data;
	new_node->next = NULL;
	return (new_node);
}

/*
Create first node and fix stack head pointing to it (to return at the end),
use another traverser pointer to build stack node by node,
create new next node -> move to next node -> create new next node -> move to next node
*/
t_node	*create_stack(int nums[], int size)
{
	int		i;
	t_node	*head;
	t_node	*traverser;		

	i = 0;
	head = create_node(nums[i++]);
	traverser = head;
	while (i < size)
	{
		traverser->next = create_node(nums[i++]);
		traverser = traverser->next;
	}
	return (head);
}

void	print_stack(t_stack stack)
{
	t_node	*traverser;

	if (stack.head)
	{
		traverser = stack.head;
		printf("%d\n", traverser->data);
	
		while (traverser->next)
		{
			traverser = traverser->next;
			printf("|\n");
			printf("%d\n", traverser->data);
		}
	}
}


int	main(void)
{
	int		nums[] = {99, 0, 25, -38, 10, 7, 42};
	t_stack	stack_a;
	int		stack_size = sizeof(nums) / sizeof(nums[0]);

	printf("stack size: %d\n", stack_size);

	if (stack_size < 2)
	{	
		write(2, "Error\n", 6);
		return (1);
	}

	stack_a.head = create_stack(nums, stack_size);
	stack_a.size = stack_size;

	print_stack(stack_a);


	return (0);
}
