/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belam <belam@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 13:29:39 by belam             #+#    #+#             */
/*   Updated: 2026/08/31 11:49:27 by belam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "error.h"

// joins 2 arrays of strings into a single array
// only works for pointers because it uses NULL to terminate
char	**ft_arrjoin(char **arr1, char **arr2)
{
	char	**joined_arr;
	size_t	arr1_len;
	size_t	arr2_len;

	arr1_len = ft_arrlen(arr1);
	arr2_len = ft_arrlen(arr2);
	joined_arr = (char **)malloc((arr1_len + arr2_len + 1) * sizeof(char *));
	if (joined_arr)
	{
		ft_memcpy(joined_arr, arr1, arr1_len * sizeof(char *));
		ft_memcpy(joined_arr + arr1_len, arr2, arr2_len * sizeof(char *));
		joined_arr[arr1_len + arr2_len] = NULL;
	}
	if (arr1)
		free(arr1);
	if (arr2)
		free(arr2);
	if (joined_arr == NULL)
		ft_error(ERR_MALLOC);
	return (joined_arr);
}
