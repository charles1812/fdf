#include "fdf.h"



void	show_map(t_data *data)
{
	mlx_clear_window(data->mlx, data->mlx_win);
	data->img = mlx_new_image(data->mlx, 1000, 800);
	data->data.img = mlx_get_data_addr(data->img, &data->data.pixel,
			&data->data.line, &data->data.endian);
	draw_background(data, 0x181C26);
	tracing(data);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
	pannel(data);
}

int     process_structure(void *mlx)
{
    mlx_loop_end(mlx);
    return (0);
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

int     main(int argc, char **argv)
{
    t_data *data;

    data = ft_calloc(1, sizeof(*data));
    data->mlx = mlx_init();
	data->fd = open(data->ag[1], O_RDONLY, 0777);
    if (data->fd == -1)
		exit(-1);
    readfile(data);
	close(data->fd);

    data->mlx_win = mlx_new_window(data->mlx, 1000, 500, "Hello world!");
    data->zoom = ft_max_zoom(100 / data->width, 2);
    show_map(data);

    mlx_hook(data->mlx_win, KeyPress, KeyPressMask, process_keypress, data->mlx);
    mlx_hook(data->mlx_win, DestroyNotify, StructureNotifyMask, process_structure, data->mlx);
    mlx_hook(data->mlx_win, ButtonPress, ButtonPressMask, process_mouse, data->mlx);

    mlx_loop_hook(data->mlx, main_loop, data);

    mlx_loop(data->mlx);

    mlx_destroy_window(data->mlx, data->mlx_win);
    mlx_destroy_display(data->mlx);
    free(data->mlx);
    return(0);
}
