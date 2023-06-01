/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_issubset.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysalmi <ysalmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 15:21:12 by ysalmi            #+#    #+#             */
/*   Updated: 2023/05/21 13:14:41 by ysalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_issubset(char *set, char *str)
{
	int	i;
	int	j;
	int	present;

	i = -1;
	while (str && set && str[++i])
	{
		present = 0;
		j = -1;
		while (set[++j])
			if (set[j] == str[i])
				present = 1;
		if (present == 0)
			return (0);
	}
	return (1);
}
