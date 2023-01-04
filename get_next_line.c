/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtasia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 17:32:46 by vtasia            #+#    #+#             */
/*   Updated: 2021/12/27 17:45:51 by vtasia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	i;

	if (!s)
		return (NULL);
	res = (char *)malloc((len + 1));
	if (!res)
		return (NULL);
	i = start;
	while (s[i] && i - start < len && start < ft_strlen(s))
	{
		res[i - start] = s[i];
		i++;
	}
	res[i - start] = '\0';
	return (res);
}

char	*ft_strdup_and_free(char *s, char *del)
{
	size_t	size;
	char	*dest;

	size = ft_strlen(s) + 1;
	dest = (char *)malloc((size));
	if (!dest || !s || size == 1)
	{
		free(del);
		free(dest);
		return (NULL);
	}
	ft_memcpy(dest, s, size);
	free(del);
	return (dest);
}

int	read_data(int fd, char **find_n, char **remainder)
{
	int		rd;
	char	*buff;

	buff = NULL;
	buff = (char *)malloc((BUFFER_SIZE + 1));
	if (!buff)
		return (-1);
	if (fd < 0 || BUFFER_SIZE < 1)
	{
		free(buff);
		return (-1);
	}
	rd = read(fd, buff, BUFFER_SIZE);
	while (rd > 0)
	{
		buff[rd] = '\0';
		*remainder = ft_strjoin_and_free(*remainder, buff);
		*find_n = ft_strchr(*remainder, '\n');
		if (*find_n)
			break ;
		rd = read(fd, buff, BUFFER_SIZE);
	}
	free(buff);
	return (rd);
}

char	*get_next_line(int fd)
{
	static char	*remainder;
	char		*str;
	char		*find_n;
	int			count;

	find_n = NULL;
	count = read_data(fd, &find_n, &remainder);
	if (count < 0 || !remainder)
		return (NULL);
	else if (count == 0)
		find_n = ft_strchr(remainder, '\n');
	if (!find_n)
	{
		str = remainder;
		remainder = NULL;
		return (str);
	}
	str = ft_substr(remainder, 0, find_n - remainder + 1);
	remainder = ft_strdup_and_free(find_n + 1, remainder);
	return (str);
}
