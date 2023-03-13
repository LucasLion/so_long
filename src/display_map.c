/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llion <llion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 13:21:57 by llion             #+#    #+#             */
/*   Updated: 2023/01/23 17:38:43 by llion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

mlx_image_t	*init_tile(t_so *so, uint32_t crop[4])
{
	uint32_t		xy[2];
	uint32_t		wh[2];
	mlx_texture_t	*sheet;
	mlx_image_t		*img;

	xy[0] = crop[0];
	xy[1] = crop[1];
	wh[0] = crop[2];
	wh[1] = crop[3];
	sheet = mlx_load_png(so->sheet);
	if (!sheet)
		ft_error();
	img = mlx_texture_area_to_image(so->mlx, sheet, wh, xy);
	mlx_delete_texture(sheet);
	if (!img)
		ft_error();
	return (img);
}

t_point	get_border_tile(t_point tile, t_point coor, t_so *so)
{
	if (coor.x == 0 && coor.y == 0)
		tile = (t_point){0, 16};
	else if (coor.x == so->width - 1 && coor.y == so->height - 1)
		tile = (t_point){3 * 16, 16};
	else if (coor.x == so->width - 1 && coor.y == 0)
		tile = (t_point){16, 16};
	else if (coor.x == 0 && coor.y == so->height - 1)
		tile = (t_point){2 * 16, 16};
	else if (coor.x == 0)
		tile = (t_point){7 * 16, 16};
	else if (coor.y == 0)
		tile = (t_point){6 * 16, 16};
	else if (coor.x == so->width - 1)
		tile = (t_point){5 * 16, 16};
	else if (coor.y == so->height - 1)
		tile = (t_point){4 * 16, 16};
	else
		tile = (t_point){16, 2 * 16};
	return (tile);
}

t_point	get_tile_sprite(char c, char d, t_point map_coor, t_so *so)
{
	t_point	tile;

	tile = (t_point){0, 0};
	if ((c == '0' || c == 'M' || c == 'E' || c == 'P' || c == 'C') && d == '1'
		&& map_coor.x != 1)
		tile = (t_point){2 * 16, 2 * 16};
	else if (c == '1')
		tile = get_border_tile(tile, (t_point)map_coor, so);
	else
		tile = (t_point){0, 2 * 16};
	return (tile);
}

void	draw_tiles(t_so *so)
{
	mlx_image_t	*img;
	t_point		tile_coors;
	int			i;
	int			j;

	i = 0;
	while (so->tab[i])
	{
		j = 0;
		while (so->tab[i][j])
		{
			tile_coors = get_tile_sprite(so->tab[i][j], so->tab[i][j - 1],
					(t_point){j, i}, so);
			img = init_tile(so, (uint32_t[4]){TS, TS, tile_coors.x,
					tile_coors.y});
			mlx_image_to_window(so->mlx, img, j * TS, i * TS);
			j++;
		}
		i++;
	}
}
