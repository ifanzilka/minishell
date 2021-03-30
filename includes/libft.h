/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarilli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 15:51:44 by bmarilli          #+#    #+#             */
/*   Updated: 2021/03/31 00:17:54 by bmarilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define M_ADD 1
# define M_REMOVE 0
# include <unistd.h>
# include <stdlib.h>

/*
** IS
*/

int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_isspace(int c);

/*
** MEM
*/

void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_calloc(size_t count, size_t size);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
void				ft_memdel(void **ap);
void				*ft_memalloc(size_t size);
int					ft_memcmp(const void *s1, const void *s2, size_t n);

/*
** NUMBERS
*/

int					ft_atoi(const char *str);
size_t				ft_intlen(long long n);
int					ft_atoi_base(char *str, char *base);
double				ft_atof(char *str);
void				ft_skip_atof(char *str, int *j);
char				*ft_itoa(int n);
char				*ft_itoa_ll(long long int n);
char				*ft_itoa_unsigned_ll(unsigned long long n);
char				*ft_itoa_with_zero(int n, int count_zero);
char				*ft_itoa_unsig_base(unsigned long long value, int base,
		int num, int reg);
char				*ft_itoa_base(unsigned long long int value,
		int base, char c);
int					ft_pow(int a, int n);

/*
** PUT
*/

int					ft_print_n_char(int num, char c, int fd);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);

/*
** STR
*/

int					ft_add_forward(char **str, char c, int n);
int					ft_add_back(char **str, char c, int n);
char				*ft_create_str(char c, int n);
int                 ft_str_find(char *str, char c);
size_t				ft_strlen(const char *str);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
char 				*ft_strcpy(char * dst, const char * src);
char				*ft_strnew(size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strnstr(const char *big, const char *little,
					size_t len);
void				ft_strdel(char **as);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				**ft_split(char const *s, char c);
char				*ft_strdup(const char *s1);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));

/*
** TO
*/

int					ft_toupper(int c);
int					ft_tolower(int c);

/*
** GARBAGE COLLECTOR
*/

void				ft_garbage_collector(void *ptr, int action);
void				*calloc_gc(size_t nmemb, size_t size);
void				*malloc_gc(size_t sizemem);
void				free_gc(void *ptr);

/*
** Sorts Algo
*/

typedef struct		s_arrinfo
{
    int             len;
    size_t          bytes;
}					t_arrinfo;

void    ft_bubble_sort(void *arr, t_arrinfo inf, int (*cmp)(void * ,void *), void (*swap_func)(void*, void*));

/*
** Array of string
*/

int     ft_arrlen(char **array);
void    ft_print_arr(char **arr);
int     ft_append_arr(char *str, char ***array);
int     ft_copy_arr(char **new, char **old, int len);
void    ft_del_str_ind(char ***array, int index);
void    ft_free_arr(char **arr, int size);
int     ft_str_cmp(void *s1, void *s2);
void    ft_swap_str(void *p1, void *p2);
void    ft_str_bubble_sort(char **array, int len);
int     ft_find_str_in_arr(char **array, char *str);

/*
** List
*/

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **lst, t_list *new);
void				ft_lstadd_back(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstdelone(t_list *lst, void (*del)(void*));
void				ft_lstdelel(t_list **lst, void *content, int (*cmp)(void *,
						void *), void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void*));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));
t_list				*ft_lst_cr_front(t_list **lst, void *content);
t_list				*ft_lst_cr_back(t_list **lst, void *content);

/*
** Two List
*/

typedef struct		s_l_list
{
	void			*content;
	struct s_l_list	*next;
	struct s_l_list	*prev;
}					t_l_list;

t_l_list			*ft_l_lsnew(void *content);
void				ft_l_lstadd_front(t_l_list **lst, t_l_list *new);
void				ft_l_lstadd_back(t_l_list **lst, t_l_list *new);
void				ft_l_lstclear(t_l_list **lst, void (*del)(void*));
void				ft_l_lstdelone(t_l_list *lst, void (*del)(void*));
void				ft_l_lstiter(t_l_list *lst, void (*f)(void *));
t_l_list			*ft_l_lstlast(t_l_list *lst);
int					ft_l_lstsize(t_l_list *lst);
t_l_list			*ft_l_lst_cr_front(t_l_list **lst, void *content);
t_l_list			*ft_l_lst_cr_back(t_l_list **lst, void *content);

/*
** Dict
*/

typedef struct		s_dict
{
    void			*key;
    void            *value;
}					t_dict;

t_dict              *ft_cr_dict(void *key, void *value);
void               *ft_find_key(t_list *dict, void *key, int (*cmp)(void *, void *));

#endif
