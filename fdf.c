#include "fdf.h"

int     process_keypress(int keysym, void *mlx)
{
    if(keysym == XK_Escape)
        mlx_loop_end(mlx);
    else if (keysym == XK_k)
        printf("salut\n");
    return (0);
}


int     process_structure(void *mlx)
{
    mlx_loop_end(mlx);
    return (0);
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

void    ft_rettangolo(void *mlx, void *mlx_win, int min_x, int min_y)
{
    int x = 0;
    int y = 0;

    while (y < 100)
    {
        x = 0;
        while(x < 200)
        {
            mlx_pixel_put(mlx, mlx_win, min_x + x, min_y + y, 0xff5733);
            x++;
        }
        y++;
    }
}

int     main_loop(t_data *data)
{
    static float     x = 200;
    static float     y = 100;

    mlx_clear_window(data->mlx, data->mlx_win);
    ft_rettangolo(data->mlx, data->mlx_win, x, y);
    if(x >= 900)
        x = 100;
    if(y >= 450)
        y = 50;
    x += 0.1;
    y += 0.1;

    return (0);
}


int     main(void)
{
    t_data *data;

    data = ft_calloc(1, sizeof(*data));
    data->mlx = mlx_init();
    data->mlx_win = mlx_new_window(data->mlx, 1000, 500, "Hello world!");

    mlx_hook(data->mlx_win, KeyPress, KeyPressMask, process_keypress, data->mlx);
    mlx_hook(data->mlx_win, DestroyNotify, StructureNotifyMask, process_structure, data->mlx);
    mlx_hook(data->mlx_win, ButtonPress, ButtonPressMask, process_mouse, data->mlx);

    mlx_loop_hook(data->mlx, main_loop, data);

    mlx_loop(data->mlx);

    mlx_destroy_window(data->mlx, data->mlx_win);
    mlx_destroy_display(data->mlx);
    free(data->mlx);
}
