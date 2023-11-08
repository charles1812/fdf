/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cspreafi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 23:05:02 by cspreafi          #+#    #+#             */
/*   Updated: 2023/04/18 23:05:05 by cspreafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *str, const char *strc)
{
	int	i;

	i = 0;
	while (str[i] && strc[i])
	{
		if (str[i] != strc[i])
			return (str[i] - strc[i]);
		i++;
	}
	return (0);
}
