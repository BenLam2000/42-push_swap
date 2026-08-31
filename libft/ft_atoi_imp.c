/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_imp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belam <belam@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 17:15:58 by belam             #+#    #+#             */
/*   Updated: 2026/08/30 15:39:02 by belam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "error.h"

/*
This version of atoi checks for overflow, underflow, non-int
This function checks sign and int only, no spaces
*/
int	ft_atoi_imp(char *s)
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
			ft_error(ERR_OVERFLOW);
		else if (sign == -1 && - num < (INT_MIN + (s[i] - '0')) / 10)
			ft_error(ERR_UNDERFLOW);
		num = num * 10 + (s[i] - '0');
		i++;
	}
	if (s[i] != '\0')
		ft_error(ERR_NON_INT);
	return (sign * num);
}
