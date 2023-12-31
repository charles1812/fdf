/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cspreafi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 14:06:33 by cspreafi          #+#    #+#             */
/*   Updated: 2023/04/17 14:20:42 by cspreafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t n)
{
	char	*a;

	if (ft_strlen(s) < start)
	{
		a = malloc(sizeof(char));
		a[0] = '\0';
		return (a);
	}
	if (ft_strlen(&s[start]) > n)
		a = malloc(sizeof(char) * n + 1);
	else
		a = malloc(sizeof(char) * ft_strlen(&s[start]) + 1);
	if (!a)
		return (NULL);
	if (ft_strlen(&s[start]) >= n)
		ft_strlcpy(a, &s[start], n + 1);
	else if (ft_strlen(&s[start]) < n)
		ft_strlcpy(a, &s[start], ft_strlen(&s[start]) + 1);
	return (a);
}
