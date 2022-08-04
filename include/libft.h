/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 18:36:17 by rlins             #+#    #+#             */
/*   Updated: 2022/08/03 18:36:49 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 128
# endif

// char	*ft_strdup(const char *s);
// char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *str);
// char	*ft_substr(char const *s, unsigned int start, size_t len);
// char	*get_next_line(int fd);
// char	**ft_split(char const *s, char c);
// char	*ft_itoa(int n);

#endif
