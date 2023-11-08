/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cspreafi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 19:07:28 by cspreafi          #+#    #+#             */
/*   Updated: 2023/04/18 19:09:14 by cspreafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	int		index;
	char	*a;

	i = 0;
	index = 0;
	if (!s || !f)
		return (NULL);
	i = ft_strlen(s);
	a = malloc(sizeof(char) * (i + 1));
	if (!a)
		return (NULL);
	while (s[index])
	{
		a[index] = f(index, s[index]);
		index++;
	}
	a[index] = '\0';
	return (a);
}
