/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtasia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 17:35:58 by vtasia            #+#    #+#             */
/*   Updated: 2021/12/27 17:37:21 by vtasia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str && str[len])
		len++;
	return (len);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!dest)
		return (NULL);
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}

size_t	ft_strlcpy(char *dest, const char *str, size_t size)
{
	size_t	len;

	len = ft_strlen(str);
	if (len + 1 < size)
		ft_memcpy(dest, str, len + 1);
	else if (size != 0)
	{
		ft_memcpy(dest, str, size - 1);
		dest[size - 1] = '\0';
	}
	return (len);
}

char	*ft_strjoin_and_free(char *str1, char *str2)
{
	char	*res;
	size_t	len_str1;
	size_t	len_str2;

	res = NULL;
	if (!str2)
		return (str1);
	len_str1 = ft_strlen(str1);
	len_str2 = ft_strlen(str2);
	res = (char *)malloc(sizeof(char) * (len_str1 + len_str2 + 1));
	if (!res)
		return (NULL);
	ft_strlcpy(res, str1, len_str1 + 1);
	ft_strlcpy(res + len_str1, str2, len_str2 + 1);
	free(str1);
	return (res);
}

char	*ft_strchr(const char *str, int c)
{
	char	comp;

	comp = c;
	while (*str)
	{
		if (*str == comp)
			return ((char *)str);
		str++;
	}
	if (*str == comp)
		return ((char *)str);
	return (NULL);
}
