#include "fdf.h"

void     get_map(t_data *data)
{
	int		i;
	char	*row;

    i = 0;
    data->height = 0;
    row = get_next_line(data->fd);
	data->width = ft_countword(row);
    while(row)
    {
        free(row);
        row = get_next_line(data->fd);
        data->height += 1;
    }
    free(row);
    data->map = malloc(sizeof(int *) * data->height);
	while (i < data->height)
	{
		data->map[i] = malloc(sizeof(int) * data->width);
		if (!data->map[i])
			exit(-1);
		i++;
	}
}


void	readfile(t_data *data)
{
	char	*str;
	char	**s_str;
	int		j;
	int		i;

	data->gnl = get_next_line(data->fd);
	get_map(data);
    if (!data->map)
		exit(-1);
	j = 0;
	while (str)
	{
		s_str = ft_split(str, ' ');
		i = 0;
		while (i < data->width)
		{
			data->map[j][i] = ft_atoi(s_str[i]);
			i++;
		}
		free(str);
		ft_free_tab(s_str);
		str = get_next_line(data->fd);
		j++;
	}
}