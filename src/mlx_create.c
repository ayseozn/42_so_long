/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aysozen <aysozen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 14:44:19 by aysozen           #+#    #+#             */
/*   Updated: 2023/10/24 20:07:48 by aysozen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx/mlx.h"
#include "so_long.h"

void	map_put(int i, int j, t_data *data)
{
	int	a;

	a = 0;
	if (data->map[i][j] == '1')
		a = mlx_put_image_to_window(data->mlx, data->win, data->img.wall, j
				* IMG_SIZE, i * IMG_SIZE);
	else if (data->map[i][j] == '0')
		a = mlx_put_image_to_window(data->mlx, data->win, data->img.bg, j
				* IMG_SIZE, i * IMG_SIZE);
	else if (data->map[i][j] == 'C')
		a = mlx_put_image_to_window(data->mlx, data->win, data->img.coin, j
				* IMG_SIZE, i * IMG_SIZE);
	else if (data->map[i][j] == 'E')
		a = mlx_put_image_to_window(data->mlx, data->win, data->img.door, j
				* IMG_SIZE, i * IMG_SIZE);
	else if (data->map[i][j] == 'P')
		a = mlx_put_image_to_window(data->mlx, data->win, data->img.character, j
				* IMG_SIZE, i * IMG_SIZE);
	if (a == -1)
	{
		map_free(data->map, data, 2);
		destroy(data);
		err_msg("image could not be printed");
	}
}

void	map_background_put(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < data->map_height)
	{
		j = 0;
		while (j < data->map_width)
		{
			if (mlx_put_image_to_window(data->mlx, data->win, data->img.bg, j
					* IMG_SIZE, i * IMG_SIZE) == -1)
			{
				map_free(data->map, data, 2);
				destroy(data);
				err_msg("image could not be printed");
			}
			map_put(i, j, data);
			j++;
		}
		i++;
	}
}

void	image_create(t_data *data)
{
	data->img.bg = mlx_xpm_file_to_image(data->mlx, "img/background.xpm",
			&data->img.img_w, &data->img.img_h);
	data->img.coin = mlx_xpm_file_to_image(data->mlx, "img/coin.xpm",
			&data->img.img_w, &data->img.img_h);
	data->img.wall = mlx_xpm_file_to_image(data->mlx, "img/wall.xpm",
			&data->img.img_w, &data->img.img_h);
	data->img.door = mlx_xpm_file_to_image(data->mlx, "img/door.xpm",
			&data->img.img_w, &data->img.img_h);
	data->img.character = mlx_xpm_file_to_image(data->mlx, "img/character.xpm",
			&data->img.img_w, &data->img.img_h);
	if (!data->img.bg || !data->img.coin || !data->img.wall || !data->img.door
		|| !data->img.character)
	{
		map_free(data->map, data, 2);
		err_msg("xpm file not found at the given location");
	}
}

static void	data_init(t_data *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, data->map_width * IMG_SIZE,
			data->map_height * IMG_SIZE, "SoLong");
}

void	mlx_create(t_data *data)
{
	data_init(data);
	image_create(data);
	map_background_put(data);
	placeholder(data, data->exit_x, data->exit_y, 0);
	if (data->i_map.read_count != data->coin_count + 1)
		err_msg("Error:\n->Map is wrong!");
	hook(data);
	mlx_loop(data->mlx);
}
