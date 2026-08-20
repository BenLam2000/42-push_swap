/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belam <belam@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 16:57:26 by belam             #+#    #+#             */
/*   Updated: 2026/08/20 20:06:57 by belam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


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
