#ifndef FDF_H
# define FDF_H

#include "libft/libft.h"
#include "minilibx-linux/mlx.h"

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}t_data;


#endif