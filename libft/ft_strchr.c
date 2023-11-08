/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cspreafi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 05:34:26 by cspreafi          #+#    #+#             */
/*   Updated: 2023/04/16 05:34:38 by cspreafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	char	*a;

	a = NULL;
	while (*str)
	{
		a = (char *)str;
		if (*str == (char)c && *str != '\0')
			return (a);
		str++;
	}
	a = (char *)str;
	if (*str == (char)c)
		return (a);
	return (NULL);
}
