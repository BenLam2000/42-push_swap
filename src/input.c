/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belam <belam@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 12:30:42 by belam             #+#    #+#             */
/*   Updated: 2026/08/31 17:16:10 by belam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include "error.h"

static char	**merge_arr(int argc, char **argv)
{
	char	**joined_arr;
	int		i;

	i = 1;
	joined_arr = NULL;
	while (i < argc)
	{
		joined_arr = ft_arrjoin(joined_arr, ft_split_strict(argv[i], ' '));
		i++;
	}
	return (joined_arr);
}

static int	*conv_num_arr(char **joined_arr, int len)
{
	int		*num_arr;
	int		i;

	num_arr = (int *)malloc(len * sizeof(int));
	if (num_arr)
	{
		i = 0;
		while (joined_arr[i])
		{
			num_arr[i] = ft_atoi_imp(joined_arr[i]);
			i++;
		}
	}
	ft_free(joined_arr);
	if (num_arr == NULL)
		ft_error(ERR_MALLOC);
	return (num_arr);
}

void	parse_input(int argc, char **argv, t_stack *stack)
{
	char	**joined_arr;
	int		*num_arr;
	size_t	len;

	joined_arr = merge_arr(argc, argv);
	len = ft_arrlen(joined_arr);
	num_arr = conv_num_arr(joined_arr, len);
	if (len < 2)
		ft_error(ERR_SIZE);
	if (ft_hasdups(num_arr, len))
		ft_error(ERR_DUP);
	if (ft_issorted(num_arr, len))
		ft_error(ERR_SORTED);
	create_stack(num_arr, len, stack);
}
