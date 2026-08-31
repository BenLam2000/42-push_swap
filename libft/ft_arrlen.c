/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belam <belam@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 14:01:12 by belam             #+#    #+#             */
/*   Updated: 2026/08/30 15:43:08 by belam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// only works for arrays that are NULL terminated
size_t	ft_arrlen(char **arr)
{
	int	i;

	i = 0;
	if (arr == NULL)
		return (i);
	while (arr[i])
		i++;
	return (i);
}
