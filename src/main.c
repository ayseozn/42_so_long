/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aysozen <aysozen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 14:43:54 by aysozen           #+#    #+#             */
/*   Updated: 2023/10/23 12:50:42 by aysozen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <fcntl.h>

int	main(int argc, char **argv)
{
	t_data	data;
	int		fd;

	if (argc != 2)
		err_msg("Error:\n->Error : Argument 2 required");
	map_control(argv, &data);
	size_control(&data, 0, 0);
	fd = open(data.map_tmp, O_RDONLY);
	if (fd == -1)
		err_msg("Error:\n->Error : Map file is not found");
	map_read(fd, &data, 0, 0);
	wall_control(&data);
	map_element(&data);
	mlx_create(&data);
}
