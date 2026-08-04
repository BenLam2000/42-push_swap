/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belam <belam@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 16:57:26 by belam             #+#    #+#             */
/*   Updated: 2026/08/04 16:37:28 by belam            ###   ########.fr       */
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

/*
error code:
1 - non-digit character
2 - space at the end or beginning
3 - multiple spaces
4 - overflow / underflow
*/
int	input_is_invalid(char **endptr)
{
	int		num_count;

	if (**endptr == ' ')
		return (2);
	num_count = 0;
	while (**endptr)
	{
		ft_atoi_imp(*endptr, endptr);
		if (**endptr == ' ' || **endptr == '\0')
		{
			num_count++;
			if (**endptr == ' ')
			{
				if (*(*endptr + 1) == '\0')
					return (2);
				else if (*(*endptr + 1) == ' ')
					return (3);
				(*endptr)++;
			}
		}
		else if (ft_isdigit(**endptr))
			return (4);
		else
			return (1);
	}
	return (0);
}
/*
0,2,4 should be numbers
1,3,5 should be spaces (does not allow consecutive spaces, start or end)
returns: number count placed in array OR -1 if invalid inputs
the prevention of increment at '\0' prevents the next while check to derefence out of bounds
*/
int	parse_input(char **endptr, int *nums)
{
	int		num_count;
	int		num;

	num_count = 0;
	while (**endptr)
	{
		num = ft_atoi_imp(*endptr, endptr);
		if (**endptr == ' ' || **endptr == '\0')
		{
			nums[num_count] = num;
			num_count++;
			if (**endptr == ' ')
				(*endptr)++;
		}
		else
			return (-1);
	}
	if (*(*endptr - 1) == ' ')
		return (-1);
	return (num_count);
}

/*
This function accepts input numbers with multiple consecutive spaces
1. loop through whole string to check how many words
2. allocate memory for char * array
*/
char	**ft_split(char const *s, char c)
{
	int		i;
	int		new_word;
	char	**word_arr;
	int		word_count;
	int		char_count;

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
	char_count = 0;
	new_word = 1;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			word_arr[word_count][char_count] = '\0';
			new_word = 1;
		}
		else
		{
			if (new_word)
			{
				word_count++;
				new_word = 0;
				char_count = 0;
			}
			word_arr[word_count - 1][char_count] = s[i];
			char_count++;
		}
		i++;
	}
	word_arr[word_count - 1][char_count] = '\0';
	return (word_arr);
}


int	main(int argc, char *argv[])
{
	char	*input = argv[1];
	char	**endptr = &input;
	//int		num_count;
	//int		*nums;

	if (argc == 2)
	{
	/*
		printf("%d\n", ft_atoi_imp(input, endptr));
		if (**endptr == '\0')
			printf("number takes up whole string");
		else if (**endptr == ' ')
			printf("preparing to check next number");
		else
			printf("invalid number! exit");
	*/

		printf("%d", input_is_invalid(endptr));
		//num_count = parse_input(endptr, nums);

		//ft_split(argv[1], ' ');
		//push_swap(argv[1]);
	}


	return (0);
}
