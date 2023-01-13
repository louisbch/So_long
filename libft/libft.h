/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbouchon <lbouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:32:11 by lbouchon          #+#    #+#             */
/*   Updated: 2023/01/12 16:38:43 by lbouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <limits.h>
# include <stdarg.h>

/*--GET_NEXT_LINE--*/

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strchr(const char *s, int c);
char	*get_next_line(int fd);

/*--FT_PRINTF.C--*/

int		ft_hex_len(unsigned int nb);
void	ft_put_hex(unsigned int nb, const char format);
int		ft_print_hex(unsigned int nb, const char format);
int		ft_unsigned_len(unsigned int nb);
char	*ft_utoa(unsigned int nb);
int		ft_print_unsigned(unsigned int nb);
int		ft_search_args(va_list args, const char format);
int		ft_printf(const char *format, ...);
int		ft_ptr_len(unsigned long nb);
void	ft_putptr(unsigned long nb);
int		ft_printptr(unsigned long nb);
int		ft_printstr(char *str);
int		ft_print_perc(void);
int		ft_printnbr(int nb);
int		ft_printchar(char c);
char	*ft_itoa(int n);

/*--LIBFT--*/

char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
size_t	ft_strlen(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strjoin(char *s1, char *s2);
char	**ft_split(char const *s, char c);
void	ft_putstr_fd(char *s, int fd);
char	*ft_strdup(const char *src);

#endif