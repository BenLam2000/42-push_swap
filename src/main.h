/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belam <belam@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 13:18:57 by belam             #+#    #+#             */
/*   Updated: 2026/08/04 16:10:15 by belam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> // DEL
#include <stdlib.h>
#include <unistd.h>
#include <limits.h> // DEL

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

t_node	*create_node(int data, t_node *prev);
int		create_stack(int nums[], int size, t_stack *stack_ptr);
void	print_stack(t_stack *stack);




