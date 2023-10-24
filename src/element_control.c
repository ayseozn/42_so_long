/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element_control.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aysozen <aysozen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 16:14:47 by aysozen           #+#    #+#             */
/*   Updated: 2023/10/13 17:24:03 by aysozen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	min_element_control(t_data *data)
{
	if (data->player_count != 1)
		err_msg("Error:\n->There must be 1 player on the map");
	if (data->exit_count != 1)
		err_msg("Error:\n->There must be 1 exit on the map");
	if (data->coin_count < 1)
		err_msg("Error:\n->Must have at least 1 collectible on the map");
	if (data->wall_count < 12)
		err_msg("Error:\n->wall error on the map");
	if (data->unwanted_character_count != 0)
		err_msg("Error:\n->The map must contain only [0,1,E,P,C] characters");
}

static void	map_element_counter(int i, int j, t_data *data)
{
	int	idiot;

	idiot = 0;
	if (data->map[i][j] == '1')
		data->wall_count++;
	else if (data->map[i][j] == '0')
		idiot++;
	else if (data->map[i][j] == 'C')
		data->coin_count++;
	else if (data->map[i][j] == 'E')
	{
		data->exit_count++;
		data->exit_x = j;
		data->exit_y = i;
	}
	else if (data->map[i][j] == 'P')
	{
		data->player_x = j;
		data->player_y = i;
		data->player_count++;
	}
	else
		data->unwanted_character_count++;
}

void	map_element(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	data->coin_count = 0;
	data->coin_collected = 0;
	data->step_count = 0;
	data->exit_count = 0;
	data->wall_count = 0;
	data->player_count = 0;
	data->unwanted_character_count = 0;
	while (i < data->map_height)
	{
		j = 0;
		while (j < data->map_width)
		{
			map_element_counter(i, j, data);
			j++;
		}
		i++;
	}
	min_element_control(data);
}
