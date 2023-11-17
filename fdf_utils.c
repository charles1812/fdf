#include "fdf.h"

int     process_keypress(int keysym, void *mlx)
{
    if(keysym == XK_Escape)
        mlx_loop_end(mlx);
    else if (keysym == XK_k)
        printf("salut\n");
    return (0);
}

int     ft_max_zoom(int one, int two)
{
    if(one > two)
        return(one);
    return(two);

}

void	draw_background(t_data *data, int color)
{
	int	x;
	int	y;

	y = 0;
	while (++y < 800)
	{
		x = 0;
		while (++x < 1000)
			put_pxl(data, x, y, color);
	}
}

int     process_mouse(int keysym, void *mlx)
{
    if (keysym == Button1)
        printf("left click\n");
    else if (keysym == Button2)
        printf("scroll click\n");
    else if (keysym == Button3)
        printf("right click\n");
    else if (keysym == Button4)
        printf("up scroll\n");
    else if (keysym == Button5)
        printf("down scroll\n");
    return (0);
}