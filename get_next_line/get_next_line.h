/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cspreafi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 03:33:07 by cspreafi          #+#    #+#             */
/*   Updated: 2023/05/02 03:33:40 by cspreafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

int		ft_strlen_line(const char *str);
int		ft_strchr_line(char *str, int c);
char	*ft_strjoin_line(char *save, char *buffer);

char	*get_next_line(int fd);
char	*read_file(int fd, char *save);
char	*ft_freejoin(char *save, char *buf);
char	*ft_delet_save(char *save);
char	*ft_cpy_line(char *line, char *save);

#endif
