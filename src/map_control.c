/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aysozen <aysozen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 14:44:05 by aysozen           #+#    #+#             */
/*   Updated: 2023/10/21 18:01:57 by aysozen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <fcntl.h>
#include "../libft/libft.h"

void	ber_control(char *map_name)
{
	int	arg_len;

	arg_len = ft_strlen(map_name);
	if (map_name[arg_len - 1] != 'r' || map_name[arg_len - 2] != 'e'
		|| map_name[arg_len - 3] != 'b' || map_name[arg_len - 4] != '.')
		err_msg("Error:\n-> Map file is not .ber");
}

void	tmp_control(char *map_name)
{
	int		fd;
	char	*line;

	fd = open(map_name, O_RDONLY);
	if (fd == -1)
		err_msg("Error:\n->Map file is not found");
	line = get_next_line(fd);
	if (!line || !line[0])
		err_msg("Error:\n->Map is Empty");
	free(line);
	close(fd);
}

void	map_control(char **argv, t_data *data)
{
	data->map_tmp = argv[1];
	ber_control(argv[1]);
	tmp_control(argv[1]);
}
