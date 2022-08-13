/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 18:36:17 by rlins             #+#    #+#             */
/*   Updated: 2022/08/13 14:15:13 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
 # include <stdarg.h> // All the macros to use variable args (va_list)

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 128
# define HEX_BASE_LOWER	"0123456789abcdef"
# define HEX_BASE_UPPER	"0123456789ABCDEF"
# define DEC_BASE		"0123456789"
# define STR_NULL		"(null)"
# define PTR_NULL		"(nil)"
# define INI_PTR		"0x"
# define NEG_PTR		"FFFFFFFF"
# endif

void	ft_free(char* ptr);
// char	*ft_strdup(const char *s);
// char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *str);
// char	*ft_substr(char const *s, unsigned int start, size_t len);
// char	*get_next_line(int fd);
// char	**ft_split(char const *s, char c);
// char	*ft_itoa(int n);

int		ft_printf(const char* str, ...);

int		ft_print_char(char c);
int		ft_print_string(char* str);
int		ft_print_dec_int(long nbr);
int		ft_print_pointer(void* ptr);
int		ft_print_hexa(unsigned int nbr, char spec);

void	ft_putchar(char c);
int		ft_putstr(char* str);
char*	ft_itoa_base(unsigned long long nbr, char* base);

#endif