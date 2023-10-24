/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aysozen <aysozen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 14:45:25 by aysozen           #+#    #+#             */
/*   Updated: 2023/10/21 17:56:30 by aysozen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../minilibx/mlx.h"

void	hook(t_data *data)
{
	mlx_hook(data->win, 2, 0, key_hook, data);
	mlx_hook(data->win, 17, 0, mouse_hook, data);
}
