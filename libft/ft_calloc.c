/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cspreafi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 05:16:19 by cspreafi          #+#    #+#             */
/*   Updated: 2023/04/16 05:16:23 by cspreafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	char	*a;

	i = count * size;
	a = malloc(i);
	if (a == NULL)
		return (NULL);
	ft_bzero(a, i);
	return (a);
}
