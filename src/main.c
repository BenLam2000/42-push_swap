/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belam <belam@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 16:57:26 by belam             #+#    #+#             */
/*   Updated: 2026/08/18 22:25:06 by belam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h> //DEL
#include <stdio.h> // DEL
#include "push_swap.h"

/*
This function swaps the top 2 nodes of a stack,
detaching and reattaching *prev and *next pointers
*/
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

// CHG SIZE back to 3
void	select_op(t_stack *stack_a, t_stack *stack_b, char *op)
{
	if ((!ft_strncmp(op, "sa", 2) || !ft_strncmp(op, "ss", 2)) && stack_a->size >= 2)
		swap(stack_a);
	if ((!ft_strncmp(op, "sb", 2) || !ft_strncmp(op, "ss", 2)) && stack_b->size >= 2)
		swap(stack_b);

	if (ft_strncmp(op, "pa", 2) == 0 && stack_b->size)
		push(stack_b, stack_a);
	else if (ft_strncmp(op, "pb", 2) == 0 && stack_a->size)
		push(stack_a, stack_b);
	printf("%s\n", op);
	print_stack(stack_a, stack_b);
}

/*
int	push_swap()
{
	//t_stack	stack_a;
	//t_stack	stack_b;

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
This function checks sign and int only, no spaces
*/
int	ft_atoi_imp(char *s, char **endptr)
{
	int	i;
	int	sign;
	int	num;

	i = 0;
	sign = 1;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}
	num = 0;
	while (ft_isdigit(s[i]))
	{
		if (sign == 1 && num > (INT_MAX - (s[i] - '0')) / 10)
			break;
		else if (sign == -1 && -num < (INT_MIN + (s[i] - '0')) / 10)
			break;
		num = num * 10 + (s[i] - '0');
		i++;
	}
	*endptr = s + i;
	return (sign * num);
}

int	main(int argc, char *argv[])
{
	char	*input_start;
	char	*input_traverser;
	char	**endptr = &input_traverser;
	t_stack	stack_a = {.head = NULL, .tail = NULL, .size = 0};
	t_stack	stack_b = {.head = NULL, .tail = NULL, .size = 0};
	int		exit_code;

	//printf("argc:%d\n", argc);

	input_start = argv[1];
	input_traverser = input_start;

	if (argc == 1)
		return (1);

	exit_code = input_to_stack(endptr, &stack_a);
	if (exit_code)
	{
		write(2, "Error\n", 6);
		return (exit_code);
	}

	print_stack(&stack_a, &stack_b);
///*
	char	buf[2];
	int		bytes_read;

	bytes_read = read(0, buf, 2);
	//printf("%d\n", bytes_read);
	while (bytes_read)
	{
		//write(1, buf, 4);
		select_op(&stack_a, &stack_b, buf);
		bytes_read = read(0, buf, 2);
		//printf("%d\n", bytes_read);
	}
//*/
/*
	select_op(&stack_a, &stack_b, "pb");
	select_op(&stack_a, &stack_b, "sa");
*/
/*
	select_op(&stack_a, &stack_b, "pb");
	select_op(&stack_a, &stack_b, "pb");
	select_op(&stack_a, &stack_b, "pb");
	select_op(&stack_a, &stack_b, "sb");
	select_op(&stack_a, &stack_b, "pa");
	select_op(&stack_a, &stack_b, "pa");
	select_op(&stack_a, &stack_b, "sb");
	select_op(&stack_a, &stack_b, "pa");
	select_op(&stack_a, &stack_b, "pa");
*/
	//printf("%d", input_is_invalid(endptr));
	//num_count = parse_input(endptr, nums);

	//push_swap(argv[1]);


	return (0);
}
