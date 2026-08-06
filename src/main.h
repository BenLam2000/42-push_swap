/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belam <belam@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 13:18:57 by belam             #+#    #+#             */
/*   Updated: 2026/08/06 18:18:06 by belam            ###   ########.fr       */
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
int		input_to_stack(char **endptr, t_stack *stackptr);
void	print_stack(t_stack *stack);
int		ft_atoi_imp(char *s, char **endptr);
int		is_input_invalid(char **endptr, int count);
int		is_sorted(t_stack *stackptr);
int		has_duplicate(t_stack *stackptr, int num);
