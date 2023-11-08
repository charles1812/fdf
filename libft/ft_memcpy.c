/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cspreafi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 05:20:44 by cspreafi          #+#    #+#             */
/*   Updated: 2023/04/16 05:27:37 by cspreafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			len;
	const char		*s;
	unsigned char	*d;

	if (!dest && !src)
		return (NULL);
	d = dest;
	s = src;
	len = 0;
	while (len < n)
	{
		d[len] = s[len];
		len++;
	}
	return (dest);
}
