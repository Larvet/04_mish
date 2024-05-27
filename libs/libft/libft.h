/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchene <bchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 11:23:07 by bchene            #+#    #+#             */
/*   Updated: 2024/05/24 11:59:25 by bchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

int				ft_atoi(const char *nptr);
long long		ft_atoll(const char *nptr);
char			*ft_itoa(int n);

int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);

int				ft_isstr_number(const char *str);
int				ft_isstr_int(const char *nptr);
int				ft_isstr_longlong(const char *nptr);

void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
void			*ft_memset(void *s, int c, size_t n);
void			ft_bzero(void *s, size_t n);
void			*ft_calloc(size_t nmemb, size_t size);

size_t			ft_strlen(const char *s);
char			*ft_strchr(const char *s, int c);
int				is_in_str(char *str, char c);
char			*ft_strswitnchr(char *s, char src, char dest);
char			*ft_strdup(const char *s);
char			*ft_strndup(char *src, int size);
char			*ft_strdupfree(char *dest, const char *src);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
size_t			ft_strlcpy(char *dst, const char *src, size_t size);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strnstr(const char *big, const char *little, size_t len);
char			*ft_strrchr(const char *s, int c);
char			*ft_substr(char const *s, unsigned int start, size_t len);

char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strjointo(char *s1, char const *s2);
char			*ft_strjointoleft(char *s1, char const *s2);
char			*ft_strjoinva(char *str, ...);

char			*ft_strtrim(char const *s1, char const *set);

char			*ft_strcpy(char *dst, const char *src);
char			*ft_strncpy(char *dst, const char *src, size_t n);

int				ft_splitsize(char **split);
int				ft_getnbsplit(char *s, char c);
void			*ft_freesplit(char **split);
char			**ft_split(char const *s, char c);

char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void			ft_striteri(char *s, void (*f)(unsigned int, char*));

int				ft_tolower(int c);
int				ft_toupper(int c);

void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);

/* Bonus liste chainee */
t_list			*ft_lstnew(void *content);
void			ft_lstadd_front(t_list **lst, t_list *node);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list **lst, t_list *node);
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *), \
void (*del)(void *));

/* mt_math */
int				mt_abs(int n);
int				mt_max(int a, int b);
int				mt_min(int a, int b);
int				mt_sign(int a);
int				mt_range(int a, int b);
float			mt_absf(float n);
float			mt_maxf(float a, float b);
float			mt_minf(float a, float b);
float			mt_signf(float a);
float			mt_rangef(float a, float b);

/* ft_randint */
int				randint(void);
unsigned int	randuint(void);
int				randintrange(int a, int b);

#endif
