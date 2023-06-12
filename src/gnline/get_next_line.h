/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbouha <oelbouha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 17:21:32 by oelbouha          #+#    #+#             */
/*   Updated: 2022/11/14 08:28:04 by oelbouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 115
# endif

# if BUFFER_SIZE < 0
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 0
# endif

# include <stdlib.h>
# include <unistd.h>
# include "../libft/inc/libft.h"

char	*get_next_line(int fd);
char	**save_buff(char **array, char *buff, int n);
char	*make_line(char **arr, char *rest, int n);
char	*ft_strncpy(char *dst, char *src, int n);
char	*concat(char *s1, char *s2);
char	*copy_to_rest(char *dest, char *src);

#endif
