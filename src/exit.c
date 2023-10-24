/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aysozen <aysozen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 14:41:38 by aysozen           #+#    #+#             */
/*   Updated: 2023/10/23 12:49:34 by aysozen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../minilibx/mlx.h"
#include "so_long.h"

void	err_msg(char *msg)
{
	ft_printf("%s", msg);
	exit(0);
}

void	map_free(char **map, t_data *data, int flag)
{
	int	i;

	i = 0;
	while (i < data->map_height)
	{
		free(map[i]);
		i++;
	}
	free(map);
	if (flag == 0)
		err_msg("Error:\n->Exit Success");
	else if (flag == 1)
		err_msg("Error:\n->Memory allocation failed!");
}

void	destroy(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img.bg);
	mlx_destroy_image(data->mlx, data->img.coin);
	mlx_destroy_image(data->mlx, data->img.wall);
	mlx_destroy_image(data->mlx, data->img.door);
	mlx_destroy_image(data->mlx, data->img.character);
	mlx_destroy_window(data->mlx, data->win);
}

int	mouse_hook(t_data *data)
{
	destroy(data);
	map_free(data->map, data, 0);
	return (0);
}

void	exit_door(t_data *data)
{
	destroy(data);
	map_free(data->map, data, 2);
	ft_printf("\n>>>>Total Movement: %d\n", data->step_count);
	err_msg("FINISH");
}
