/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belam <belam@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 12:30:42 by belam             #+#    #+#             */
/*   Updated: 2026/08/18 12:42:44 by belam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_invalid_space(char *endptr, char *endptr_prev)
{
	return ((endptr == endptr_prev && *endptr == ' ') ||\
		(endptr > endptr_prev && *endptr == ' ' && *(endptr + 1) == '\0'));
}

static int	is_non_int(char *endptr)
{
	return (*endptr != ' ' && *endptr != '\0' && !ft_isdigit(*endptr));
}

static int	is_overflow_underflow(char *endptr, char *endptr_prev)
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
