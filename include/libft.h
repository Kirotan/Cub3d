/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <gdoumer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 15:57:22 by gdoumer           #+#    #+#             */
/*   Updated: 2024/08/14 15:57:23 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# define NEW 1
# define DELETE 2
# define CLEAR 3
# define MALLOC_FAIL "Error: malloc failed.\n"
# define ERR "Error\n"

# if (BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX)
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <limits.h>
# include <stdint.h>
# include <stdio.h>

typedef struct s_malloc_ptr
{
	void				*ptr;
	struct s_malloc_ptr	*next;
}	t_malloc_ptr;

int		ft_isalpha(int charac);
void	del_if_same(t_malloc_ptr *l_m, t_malloc_ptr *tmp, void *var);
int		ft_error(char *msg_err);
void	*ft_alloc(int size, unsigned long type);
void	*ft_del_alloc(void *var);
void	*ft_del_all(void);
void	*malloc_factory(size_t size, int action, void *ptr, unsigned long type);
char	*ft_strchr(const char *string, int searched_char);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *source);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
void	ft_putstr_fd(char *s, int fd);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_bzero(void *s, size_t n);
int		ft_isdigit(int charac);
int		ft_atoi(const char *str);
int		ft_strncmp(const char *first, const char *second, size_t length);

#endif
