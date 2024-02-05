#include "fdf.h"

int     ft_max_zoom(int one, int two)
{
    if(one > two)
        return(one);
    return(two);
}

void	projection(float *x, float *y, int *z, t_data *data)
{
	int	x_tmp;
	int	y_tmp;

	*z = data->map[(int)*y][(int)*x];
	*z *= data->zoom;
	*z *= data->h_view;
	*y *= data->zoom;
	*x *= data->zoom;
	y_tmp = *y;
	x_tmp = *x;
	*x = (*x - *y) * cos(0.8);
	*y = (*x + *y) * sin(0.8) - *z;
}

void	put_pxl(t_data *data, int x, int y, int color)
{
	int		i;

	i = (x * data->data.pixel / 8) + (y * data->data.line);
	data->data.img[i] = color;
	data->data.img[++i] = color >> 8;
	data->data.img[++i] = color >> 16;
}

void	trace_line(float x0, float y0, t_data *data)
{
	int		z0;
	int		z1;
	float	x_step;
	float	y_step;
	int		max;

	projection(&x0, &y0, &z0, data);
	projection(&data->x, &data->y, &z1, data);
	x0 += data->h_move;
	y0 += data->v_move;
	data->x += data->h_move;
	data->y += data->v_move;
	x_step = data->x - x0;
	y_step = data->y - y0;
	max = find_max(find_mod(x_step), find_mod(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(x0 - data->x) || (int)(y0 - data->y))
	{
		if (x0 < 1000 && y0 < 800 && x0 > 0 && y0 > 0)
			put_pxl(data, x0, y0, fade(find_max(z0, z1)));
		x0 += x_step;
		y0 += y_step;
	}
}

void	tracing(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			if (j < data->width - 1)
			{
				data->x = j + 1;
				data->y = i;
				trace_line(j, i, data);
			}
			if (i < data->height - 1)
			{
				data->x = j;
				data->y = i + 1;
				trace_line(j, i, data);
			}
			j++;
		}
		i++;
	}
}