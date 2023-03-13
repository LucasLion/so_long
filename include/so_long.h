/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llion <llion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 13:24:59 by llion             #+#    #+#             */
/*   Updated: 2023/01/24 15:31:53 by llion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# define SO_LONG_H

# include "/Users/llion/cursus/MLX42/include/MLX42/MLX42.h"
# include "../libft/libft.h"

# define TS 16
# define SSS 10

typedef struct s_point
{
	int				x;
	int				y;
}					t_point;

typedef struct s_player
{
	int				state;
	t_point			*tile_coors;
	t_point			*pos;
	mlx_image_t		*img;
	mlx_texture_t	*texture;

}					t_player;

typedef struct s_element
{
	char			c;
	int				of;
	t_point			*tile_coors;
	mlx_image_t		*img;
	mlx_texture_t	*texture;

}					t_elem;

typedef struct s_so
{
	mlx_t			*mlx;
	t_list			*map;
	t_elem			*collectible;
	t_elem			*enemy;
	t_elem			*d;
	t_elem			*s;
	t_player		*p;
	mlx_image_t		*text;
	char			*sheet;
	char			**tab;
	t_point			*start;
	int				objects_picked;
	int				*objects;
	int				steps;
	int				width;
	int				item_num;
	int				enemy_num;
	int				begin;
	int				exit;
	int				entrance;
	int				height;
	int				rect;
	int				top_bottom;
	int				left_right;
}					t_so;

void				init_map(t_so *so);
int					arg_check(char **argv);
t_list				*fill_map(int fd);
int					get_map_height(t_so *so);
int					check_map_rect(t_so *so);
char				**fill_tab_with_list(t_so *so);
int					check_top_bottom(char **tab);
int					check_left_right(char **tab);
int					check_errors(char **tab);
void				get_start_and_count_elems(t_so *so);
int					*flood_fill(char **tab, t_point cur, t_point size,
						char to_fill);
char				**tabcpy(t_so *so);
int					get_map_objects_and_values(t_so *so);
int					return_errors(t_so *so);
void				print_errors(t_so *so);
int					check_map(t_so *so);
t_point				get_border_tile(t_point tile, t_point coor, t_so *so);
t_point				get_tile_sprite(char c, char d, t_point map_coor,
						t_so *so);

/* ------------ CROPPING ---------------- */

int					loop_game(t_so *so);
mlx_image_t			*init_tile(t_so *so, uint32_t crop[4]);
void				draw_tiles(t_so *so);
void				ft_error(void);

/* ------------ UTILS ---------------- */

void				create_items_list(t_so *so);

/* ------------ FREE ---------------- */

void				free_tab(char **tab);

/* ------------ HOOKS ---------------- */

void				hook(void *param);
void				move_player(mlx_key_data_t keydata, void *param);
void				manage_player_movement(t_so *so, int n);

/* -------------- GAME ---------------- */

void				init_elems(t_so *so);
void				init_elems2(t_so *so);
mlx_image_t			*create_img(t_so *so, uint32_t crop[4]);
int					loop_game(t_so *so);
void				create_player(t_so *so);
void				draw_player(t_so *so, int x);
void				draw_elems(t_so *so);
void				collide_item(void *param);

/* -------------- ANIMATIONS ---------------- */

void				animate_element(t_elem *elem, t_point ***tab);

#endif
