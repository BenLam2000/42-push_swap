/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belam <belam@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 17:17:46 by belam             #+#    #+#             */
/*   Updated: 2026/08/31 11:46:28 by belam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# define ERR_NO_ARGS 1
# define ERR_SPACE 2
# define ERR_OVERFLOW 3
# define ERR_UNDERFLOW 4
# define ERR_NON_INT 5
# define ERR_SIZE 6
# define ERR_DUP 7
# define ERR_SORTED 8
# define ERR_MALLOC 9

void	ft_error(int exit_code);
#endif
