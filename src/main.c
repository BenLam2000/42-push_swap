/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belam <belam@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 16:57:26 by belam             #+#    #+#             */
/*   Updated: 2026/08/10 16:25:20 by belam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

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


int	ft_isdigit(char a)
{
	return (a >= '0' && a <= '9');
}

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



int	is_invalid_space(char *endptr, char *endptr_prev)
{
	return ((endptr == endptr_prev && *endptr == ' ') ||\
		(endptr > endptr_prev && *endptr == ' ' && *(endptr + 1) == '\0'));
}

int	is_non_int(char *endptr)
{
	return (*endptr != ' ' && *endptr != '\0' && !ft_isdigit(*endptr));
}

int	is_overflow_underflow(char *endptr, char *endptr_prev)
{
	return (endptr > endptr_prev && ft_isdigit(*endptr));
}

/*
error code:
2 - space at the end or beginning, or consecutive spaces
3 - non-int number
4 - overflow / underflow

0,2,4 should be numbers
1,3,5 should be spaces (does not allow consecutive spaces, start or end)
the prevention of increment at '\0' prevents the next while check to derefence out of bounds
reason for invalid instead of valid (flip logic), so can represent many error codes
*/
int	is_input_invalid(char *endptr, char *endptr_prev)
{
	if (is_invalid_space(endptr, endptr_prev))
		return (2);
	else if (is_non_int(endptr))
		return (3);
	else if (is_overflow_underflow(endptr, endptr_prev))
		return (4);
	else 
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

/*
*/
int	main(int argc, char *argv[])
{
	char	*input_start;
	char	*input_traverser;
	char	**endptr = &input_traverser;
	t_stack	stack_a = {.head = NULL, .tail = NULL, .size = 0};
	int		exit_code;

	printf("argc:%d\n", argc);

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

	print_stack(&stack_a);
	

	//printf("%d", input_is_invalid(endptr));
	//num_count = parse_input(endptr, nums);

	//push_swap(argv[1]);


	return (0);
}
