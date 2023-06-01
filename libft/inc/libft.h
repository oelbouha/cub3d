/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysalmi <ysalmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 12:44:13 by ysalmi            #+#    #+#             */
/*   Updated: 2023/05/13 18:25:07 by ysalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef enum e_bool
{
	FALSE,
	TRUE
}	t_bool;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

typedef struct s_syntax
{
	char	flags[6];
	int		width;
	int		precision;
	char	type;
	int		length;
}	t_syntax;

typedef void				(*t_lstdel)(void *);
typedef int					(*t_lstcmp)(void *);

/*****************************************************************************/
/*	libft																	 */
/*****************************************************************************/
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isprint(int c);
int		ft_isascii(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);
size_t	ft_strlen(char const *str);
size_t	ft_strlcpy(char *dst, char const *src, size_t size);
size_t	ft_strlcat(char *dst, char const *src, size_t size);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_templatecmp(const char *str, const char *template, char delimiter);
int		ft_issubset(char *set, char *str);
char	*ft_strchr(const char *str, int c);
char	*ft_strrchr(const char *str, int c);
char	*ft_strnstr(const char *big, const char *little, size_t n);
char	*ft_stristr(const char *big, const char *little);
char	*ft_strdup(const char *str);
void	*ft_bzero(void *dst, size_t len);
void	*ft_memset(void *dst, int c, size_t len);
void	*ft_memcpy(void *dst, const void *src, size_t len);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memchr(const void *b, int c, size_t len);
int		ft_memcmp(void *b1, void *b2, size_t len);
int		ft_atoi(const char *nbr);
void	*ft_calloc(size_t n, size_t size);
void	free_arr(char **arr);

char	*ft_replace(char *str, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
int		num_splits(const char *s, char c);
char	**ft_split(char const *str, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new_node);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new_node);
void	ft_lstdelone(t_list *lst, t_lstdel del);
void	ft_lstdel_first(t_list **head, t_lstdel del);
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
void	ft_lstremove_if(t_list **lst, t_lstcmp need_rm, t_lstdel del);
char	**ft_lst_to_arr(t_list *lst);

/*****************************************************************************/
/*	ft_printf																 */
/*****************************************************************************/
int		ft_printf(const char *s, ...);// __attr__ ((format (printf, 1, 2)));
int		ft_print_str(const char *s, va_list args);
int		ft_print_const_str(const char *s);
int		ft_print_variable(const char *s, va_list args, int *cursor);

int		ft_pad_left(t_syntax syntax, int reserved);
int		ft_pad_right(t_syntax syntax, int reserved);

int		print_char(t_syntax syntax, char c);
int		print_str(t_syntax syntax, char *s);
int		print_pointer(t_syntax syntax, void *p);
int		print_number(t_syntax syntax, int n);
int		print_hex(t_syntax syntax, int n);

int		get_num_length(unsigned int n);
int		get_num_hex_length(unsigned long n);
int		print_num_in_hex(unsigned long n, int uppercase);
#endif
