/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_append_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belam <belam@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 13:09:24 by belam             #+#    #+#             */
/*   Updated: 2026/08/30 13:09:28 by belam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// assumes there is 1 extra byte in the buffer for null terminator
void	ft_append_char(char *str, char a)
{
	while (*str)
		str++;
	*str = a;
	*(str + 1) = '\0';
}
