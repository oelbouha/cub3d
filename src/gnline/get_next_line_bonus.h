/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbouha <oelbouha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 17:21:32 by oelbouha          #+#    #+#             */
/*   Updated: 2022/11/14 08:29:26 by oelbouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# if BUFFER_SIZE < 0
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 0
# endif

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

char	*get_next_line(int fd);
char	**save_buff(char **array, char *buff, int n);
char	*make_line(char **array, char *rest, int n);
char	*ft_strchr(const char *s, int c);
int		ft_strlen(const char *str);
char	*ft_strncpy(char *dst, char *src, int n);
char	*ft_strchr(const char *s, int c);
char	*concat(char *s1, char *s2);
char	*copy_to_rest(char *dest, char *src);

#endif
