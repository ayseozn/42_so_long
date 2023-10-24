/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_control.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aysozen <aysozen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 14:46:49 by aysozen           #+#    #+#             */
/*   Updated: 2023/10/21 18:02:57 by aysozen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <fcntl.h>
#include "../libft/libft.h"

void	map_read(int fd, t_data *data, int i, int j)
{
	char	*area;

	data->map = (char **)malloc(sizeof(char *) * data->map_height);
	if (!data->map)
		map_free(data->map, data, 1);
	while (i < data->map_height)
	{
		j = 0;
		area = get_next_line(fd);
		if (area == NULL)
			break ;
		data->map[i] = (char *)malloc(sizeof(char) * data->map_width);
		if (!data->map[i])
			map_free(data->map, data, 1);
		while (j < data->map_width)
		{
			data->map[i][j] = area[j];
			j++;
		}
		data->map[i][j] = '\0';
		i++;
		free(area);
	}
	close(fd);
}

void	size_control(t_data *data, int x, int y)
{
	int		fd;
	char	*line;

	fd = open(data->map_tmp, O_RDONLY);
	if (fd == -1)
		err_msg("Error:\n->Map file is not found");
	line = get_next_line(fd);
	x = ft_strlen(line);
	while (1)
	{
		free(line);
		y++;
		line = get_next_line(fd);
		if (line[0] == '\0')
			break ;
		if (x != (int)ft_strlen(line) && line[0] != '\0')
			err_msg("Error:\n->Map is not rectangular");
	}
	if (!line)
		free(line);
	data->map_height = y;
	data->map_width = x - 1;
	close(fd);
}

void	wall_control(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < data->map_width)
		if (data->map[0][x++] != '1')
			err_msg("Error:\n->The map has to be surrounded by walls");
	while (y < data->map_height)
	{
		if (data->map[y][0] != '1' || data->map[y][data->map_width - 1] != '1')
			err_msg("Error:\n->The map has to be surrounded by walls");
		y++;
	}
	x = 0;
	while (x < data->map_width)
		if (data->map[data->map_height - 1][x++] != '1')
			err_msg("Error:\n->The map has to be surrounded by walls");
}
