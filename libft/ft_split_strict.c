/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_strict.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belam <belam@student.42iskandarputeri.edu  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 15:49:05 by belam             #+#    #+#             */
/*   Updated: 2026/08/31 16:33:46 by belam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "error.h"

static int	count_words(char *s, char c)
{
	int	new_word;
	int	word_count;
	int	index;

	new_word = 1;
	word_count = 0;
	index = -1;
	while (*s)
	{
		if (*s != c && new_word)
		{
			index++;
			word_count++;
			new_word = 0;
		}
		else if (*s == c && !new_word)
		{
			index++;
			if (index % 2 == 0 || *(s + 1) == '\0')
				ft_error(ERR_SPACE);
			new_word = 1;
		}
		s++;
	}
	return (word_count);
}

void	fill_str(char **strs, int word_count, char *s, char *word_start)
{
	if (word_count > 0)
	{
		strs[word_count - 1] = ft_substr(word_start, 0, s - word_start);
		if (strs[word_count - 1] == NULL)
		{
			ft_free(strs);
			ft_error(ERR_MALLOC);
		}
	}
	strs[word_count] = NULL;
}

// dep: malloc
// 'break' prevents scenario s[i] == NULL, enters last if, 
// and malloc 2nd time, hence lost bytes if s ends with c, ex: "ab c ", 
// allocate 2 bytes twice at c and '\0'
static void	alloc_fill_str(char **strs, char *s, char c)
{
	int		new_word;
	int		word_count;
	char	*word_start;

	new_word = 1;
	word_count = 0;
	while (*s)
	{
		if (*s != c && new_word)
		{
			word_start = s;
			word_count++;
			new_word = 0;
		}
		else if (*s == c && !new_word)
		{
			fill_str(strs, word_count, s, word_start);
			new_word = 1;
		}
		s++;
	}
	fill_str(strs, word_count, s, word_start);
}

void	ft_free(char **strs)
{
	int	i;

	if (strs == NULL)
		return ;
	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

char	**ft_split_strict(char *s, char c)
{
	char	**strs;
	int		word_count;

	word_count = count_words(s, c);
	strs = (char **)malloc((word_count + 1) * sizeof(char *));
	if (!strs)
		ft_error(ERR_MALLOC);
	alloc_fill_str(strs, s, c);
	return (strs);
}
