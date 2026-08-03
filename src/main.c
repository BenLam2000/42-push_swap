/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belam <belam@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 16:57:26 by belam             #+#    #+#             */
/*   Updated: 2026/08/03 15:09:27 by belam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_node 
{
	int				data;
	struct s_node	*next;
	struct s_node	*prev;
} t_node;

typedef struct	s_stack
{
	t_node	*head;
	t_node	*tail;
	int		size;
} t_stack;

/*
This function creates a new stack node,
places data in it, then links it to NULL
next node in the linked list will simply override NULL
*/
t_node	*create_node(int data, t_node *prev)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->data = data;
	new_node->prev = prev;
	new_node->next = NULL;
	return (new_node);
}

/*
Create first node and fix stack head pointing to it (to return at the end),
use another traverser pointer to build stack node by node,
create new next node -> move to next node -> create new next node -> move to next node
*/
int	create_stack(int nums[], int size, t_stack *stack_ptr)
{
	int		i;
	t_node	*head;
	t_node	*traverser;		

	i = 0;
	head = create_node(nums[i++], NULL);
	if (!head)
		return (0);
	traverser = head;
	while (i < size)
	{
		traverser->next = create_node(nums[i], traverser);
		if (!(traverser->next))
			return (0);
		traverser = traverser->next;
		i++;
	}
	stack_ptr->head = head;
	stack_ptr->tail = traverser;
	stack_ptr->size = size;
	return (1);
}

void	print_stack(t_stack *stack)
{
	t_node	*traverser;

	printf("forwards:\n");
	if (stack->head)
	{
		traverser = stack->head;
		while (traverser)
		{
			printf("%4d\n", traverser->data);
			printf("%4s\n", " | ");
			traverser = traverser->next;
		}
	}
	printf("%4s\n", "NULL");

	printf("backwards:\n");
	if (stack->tail)
	{
		traverser = stack->tail;
		while (traverser)
		{
			printf("%4d\n", traverser->data);
			printf("%4s\n", " | ");
			traverser = traverser->prev;
		}
	}
	printf("%4s\n", "NULL");
}

/*
This function swaps the top 2 nodes of a stack,
detaching and reattaching *prev and *next pointers
*/
void	swap(t_stack *stack)
{
	t_node	*node1;
	t_node	*node2;

	node1 = stack->head;
	node2 = stack->head->next;
	node1->next = node2->next;
	node2->next->prev = node1;
	node2->next = node1;
	node1->prev = node2;
	node2->prev = NULL;
	stack->head = node2;
}

/*
void	swap_a()
{
	
}
*/

/*
int	push_swap()
{
	//int		*stack_a_nums = (int *)malloc(sizeof(int) * 3); //{99, 0, 25};
	//int		stack_b_nums[] = {-38, 10, 7, 42};
	//int		stack_a_size = sizeof(stack_a_nums) / sizeof(stack_a_nums[0]);
	//int		stack_b_size = sizeof(stack_b_nums) / sizeof(stack_b_nums[0]);
	//t_stack	stack_a;
	//t_stack	stack_b;

	//printf("stack size: %d\n", stack_a_size);

	if (stack_a_size < 2)
		return (1);

	if (!create_stack(stack_a_nums, stack_a_size, &stack_a))
		return (1);
	if (!create_stack(stack_b_nums, stack_b_size, &stack_b))
		return (1);

	print_stack(&stack_a);
	print_stack(&stack_b);

	swap(&stack_a);
	swap(&stack_b);

	print_stack(&stack_a);
	print_stack(&stack_b);

}
*/

/*
This function accepts input numbers with multiple consecutive spaces
1. loop through whole string to check how many words
2. allocate memory for char * array
*/
char	**ft_split(char const *s, char c)
{
	int	word_count;
	int	i;
	int	new_word;

	word_count = 0;
	new_word = 1;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			new_word = 1;
		else
		{
			if (new_word)
			{
				word_count++;
				new_word = 0;
			}
		}
		i++;
	}
	printf("word count: %d\n", word_count);

	word_arr = (char **)malloc(sizeof(char *) * (word_count + 1));

	word_count = 0;
	char_count = 0;
	new_word = 1;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			new_word = 1;
			word_arr[word_count - 1] = (char *)malloc(sizeof(char) * (char_count + 1));
		}
		else
		{
			if (new_word)
			{
				word_count++;
				new_word = 0;
				char_count = 0;
			}
			char_count++;
		}
		i++;
	}
	word_arr[word_count] = NULL;
	
	word_count = 0;
	word_i = 0;
	new_word = 1;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			word_arr[word_count][word_i] = '\0';
			new_word = 1;
		}
		else
		{
			if (new_word)
			{
				word_count++;
				new_word = 0;
				word_i = 0;
			}
			word_arr[word_count - 1][word_i] = s[i];
			word_i++;
		}
		i++;
	}
	word_arr[word_count - 1][word_i] = '\0';
	return (word_arr);
}


int	main(int argc, char *argv[])
{
	if (argc == 2)
		ft_split(argv[1], ' ');
		//push_swap(argv[1]);
	


	return (0);
}
