/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 07:05:38 by rlins             #+#    #+#             */
/*   Updated: 2022/08/13 14:29:45 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/libft.h"

char	*get_next_line(int fd)
{
	static char		*accumulator;
	char			*result;
	char			*buffer;
	int				read_size;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) == -1)
		return (NULL);
	buffer = malloc(sizeof(char *) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	read_size = 1;
	while (read_size > 0 && ft_strchr(accumulator, '\n') == NULL)
	{
		read_size = read(fd, buffer, BUFFER_SIZE);
		if (read_size > 0)
		{
			buffer[read_size] = '\0';
			accumulator = ft_strjoin(accumulator, buffer);
		}
	}
	free(buffer);
	result = fix_line (accumulator);
	accumulator = get_newtext (accumulator);
	return (result);
}

char	*get_newtext(char *acc)
{
	char	*result;
	int		count;
	int		i;

	count = 0;
	i = 0;
	if (!acc || !acc[0])
	{
		free (acc);
		return (NULL);
	}
	while (acc[count] && acc[count] != '\n')
		count++;
	result = (char *)malloc((sizeof(char) * (ft_strlen(acc) - count) + 1));
	if (!result)
		return (NULL);
	if (acc[count] == '\n')
		count++;
	while (acc[count])
		result[i++] = acc[count++];
	result[i] = '\0';
	free(acc);
	return (result);
}

char	*fix_line(char *text)
{
	int		size_line;
	char	*result;
	int		i;

	i = 0;
	size_line = 0;
	if (!text || !text[0])
		return (NULL);
	while (text[size_line] && text[size_line] != '\n')
		size_line++;
	result = (char *)malloc((sizeof(char) * (size_line + 2)));
	if (!result)
		return (NULL);
	while (text[i] && text[i] != '\n')
	{
		result[i] = text[i];
		i++;
	}
	if (text[i] && text[i] == '\n')
	{
		result[i] = '\n';
		i++;
	}
	result[i] = '\0';
	return (result);
}
