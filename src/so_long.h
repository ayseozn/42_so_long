/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aysozen <aysozen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 14:46:14 by aysozen           #+#    #+#             */
/*   Updated: 2023/10/21 18:03:27 by aysozen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define IMG_SIZE 100

typedef struct l_image
{
	char		*character;
	char		*wall;
	char		*coin;
	char		*door;
	char		*bg;
	int			img_w;
	int			img_h;
}				t_image;

typedef struct l_int_map
{
	int			read_count;
}				t_int_map;

typedef struct l_data
{
	char		**map;
	char		*mlx;
	char		*win;
	char		*map_tmp;
	int			map_width;
	int			map_height;
	int			player_x;
	int			player_y;
	int			player_count;
	int			exit_count;
	int			exit_x;
	int			exit_y;
	int			wall_count;
	int			coin_count;
	int			unwanted_character_count;
	int			coin_collected;
	int			step_count;
	t_image		img;
	t_int_map	i_map;
}				t_data;

void			mlx_create(t_data *data);
void			map_control(char **argv, t_data *data);
void			ber_control(char *map_name);
void			tmp_control(char *map_name);
void			map_read(int fd, t_data *data, int i, int j);
void			size_control(t_data *data, int x, int y);
void			*myfree(void *str);
char			*get_next_line(int fd);
void			err_msg(char *msg);
void			hook(t_data *data);
int				key_hook(int keycode, t_data *data);
int				mouse_hook(t_data *data);
void			exit_door(t_data *data);
void			map_background_put(t_data *data);
void			map_put(int i, int j, t_data *data);
void			placeholder(t_data *list, int x, int y, int i);
void			wall_control(t_data *data);
int				press(t_data *data);
int				ft_printf(const char *str, ...);
void			map_element(t_data *data);
void			map_free(char **map, t_data *data, int flag);
void			destroy(t_data *data);
#endif
