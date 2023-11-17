#ifndef FDF_H
# define FDF_H

#include "libft/libft.h"
#include "get_next_line/get_next_line.h"
#include "minilibx-linux/mlx.h"
#include <X11/X.h>
#include <X11/keysym.h>
#include <X11/Xlib.h>

#include <math.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <fcntl.h>


typedef struct s_img_data
{
    int         pixel;
    int         line;
    int         endian;
    char    *img;
}   t_img_data;


typedef struct	s_data {
	t_img_data      data;
    
    void            *mlx;
    void            *mlx_win;
    int                 **map;
    char            *img;
    float           x;
    float           y;
    char            **ag;
    int                 fd;
    int                 height;
    int                 width;
    char            *gnl;
    char            **strs;
    float           zoom;
    int                 y_move;
    int                 x_move;
    float           h_view;

}t_data;


#endif