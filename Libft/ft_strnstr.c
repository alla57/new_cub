/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alla <alla@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 11:27:48 by alboumed          #+#    #+#             */
/*   Updated: 2021/10/15 22:22:09 by alla             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (haystack[i] && needle[j] && len > 0)
	{
		j = 0;
		if (needle[j] != haystack[i])
		{
			i++;
			len--;
		}
		while (needle[j] == haystack[i] && len > 0 && haystack[i])
		{
			j++;
			i++;
			len--;
		}
	}
	if (needle[j] == '\0')
		return ((char *)haystack + (i - j));
	return (NULL);
}
