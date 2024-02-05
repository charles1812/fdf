/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cspreafi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 18:41:31 by cspreafi          #+#    #+#             */
/*   Updated: 2023/05/01 22:13:34 by cspreafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

int	ft_strlen_line(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

int	ft_strchr_line(char *str, int c)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
			return (1);
		i++;
	}
	if (str[i] == (char)c)
		return (1);
	return (0);
}

char	*ft_strjoin_line(char *save, char *buffer)
{
	int		i;
	int		j;
	char	*result;

	i = 0;
	j = 0;
	if (!buffer)
		return (save);
	result = malloc(sizeof(char) * (ft_strlen_line(save) + ft_strlen_line(buffer)) + 1);
	if (!result)
		return (NULL);
	while (save[i])
	{
		result[i] = save[i];
		i++;
	}
	while (buffer[j])
		result[i++] = buffer[j++];
	result[i] = '\0';
	return (result);
}
