/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysalmi <ysalmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 09:47:09 by ysalmi            #+#    #+#             */
/*   Updated: 2023/01/28 11:47:08 by ysalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			num_splits(const char *s, char c);
static int	*next_substr(const char *s, char c, int *data);
static char	**free_mem(char **arr, int n);

char	**ft_split(const char *s, char c)
{
	char	**strs;
	int		strs_len;
	int		data[2];
	int		i;

	if (!s)
		return (0);
	strs_len = num_splits(s, c);
	strs = malloc((strs_len + 1) * sizeof(char *));
	if (!strs)
		return (0);
	data[0] = 0;
	data[1] = 0;
	i = -1;
	while (++i < strs_len)
	{
		next_substr(s, c, data);
		strs[i] = ft_substr(s, data[0], data[1]);
		if (! strs[i])
			return (free_mem(strs, i));
	}
	strs[i] = 0;
	return (strs);
}

int	num_splits(const char *s, char c)
{
	int	n;
	int	i;

	n = 0;
	i = -1;
	while (s[++i] == c && s[i])
		;
	i--;
	while (s[++i])
	{
		if (s[i] == c)
		{
			n++;
			while (s[++i] == c)
				;
			i--;
		}
	}
	if (i > 0)
		if (s[--i] != c)
			n++;
	return (n);
}

static int	*next_substr(const char *s, char c, int *data)
{
	int	i;

	i = data[0] + data[1];
	while (s[i] == c)
		i++;
	data[0] = i;
	while (s[i] && s[i] != c)
		i++;
	data[1] = i - data[0];
	return (data);
}

static char	**free_mem(char **arr, int n)
{
	int	i;

	i = 0;
	while (i < n)
		free(arr[i++]);
	free(arr);
	return (0);
}
