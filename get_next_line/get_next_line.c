/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cspreafi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 14:49:09 by cspreafi          #+#    #+#             */
/*   Updated: 2023/05/01 22:13:03 by cspreafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

char	*ft_cpy_line(char *line, char *save)
{
	int	i;

	i = 0;
	if (!save[i])
		return (NULL);
	while (save[i] != '\n' && save[i])
		i++;
	if (save[i] && save[i] == '\n')
		line = (char *)malloc(sizeof(char) * (i + 2));
	else
		line = (char *)malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (save[i] && save[i] != '\n')
	{
		line[i] = save[i];
		i++;
	}
	if (save[i] == '\n' && save[i])
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*ft_delet_save(char *save)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	j = 0;
	while (save[i] != '\n' && save[i] != '\0')
		i++;
	if (!save[i] || !save[++i])
	{
		free(save);
		return (NULL);
	}
	temp = malloc (sizeof(char) * (ft_strlen_line(save) - i + 1));
	if (!temp)
	{
		free(save);
		return (NULL);
	}
	while (save[i])
		temp[j++] = save[i++];
	temp[j] = '\0';
	free(save);
	return (temp);
}

char	*ft_freejoin(char *save, char *buf)
{
	char	*temp;

	if (!save)
	{
		save = (char *)malloc(sizeof(char));
		if (!save)
			return (NULL);
		save[0] = '\0';
	}
	temp = ft_strjoin_line(save, buf);
	free(save);
	if (!temp)
		return (NULL);
	return (temp);
}

char	*read_file(int fd, char *save)
{
	char	*buf;
	int		file_read;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	file_read = 1;
	while (file_read > 0)
	{
		file_read = read(fd, buf, BUFFER_SIZE);
		if (file_read == -1)
		{
			free(save);
			free(buf);
			return (NULL);
		}
		buf[file_read] = '\0';
		save = ft_freejoin(save, buf);
		if (ft_strchr_line(buf, '\n'))
			break ;
	}
	free(buf);
	return (save);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 256)
		return (NULL);
	save = read_file(fd, save);
	if (!save)
		return (NULL);
	line = ft_cpy_line(line, save);
	save = ft_delet_save(save);
	return (line);
}
