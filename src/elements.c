/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elements.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llion <llion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:57:54 by llion             #+#    #+#             */
/*   Updated: 2023/01/23 17:49:49 by llion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_elems2(t_so *so)
{
	so->d = malloc(sizeof(t_elem));
	if (so->d == NULL)
		return ;
	so->d->tile_coors = malloc(sizeof(t_point));
	*so->d->tile_coors = (t_point){16, 6 * 16};
	so->d->tile_coors->y -= 2;
	so->d->of = 2;
	so->d->img = create_img(so, (uint32_t[4]){TS, TS + so->d->of,
			so->d->tile_coors->x, so->d->tile_coors->y});
	so->s = malloc(sizeof(t_elem));
	if (so->s == NULL)
		return ;
	so->s->tile_coors = malloc(sizeof(t_point));
	*so->s->tile_coors = (t_point){0, 6 * 16};
	so->s->tile_coors->y -= TS;
	so->s->of = TS;
	so->s->img = create_img(so, (uint32_t[4]){TS, TS + so->s->of,
			so->s->tile_coors->x, so->s->tile_coors->y});
}

void	init_elems(t_so *so)
{
	so->collectible = malloc(sizeof(t_elem));
	if (so->collectible == NULL)
		return ;
	so->collectible->tile_coors = malloc(sizeof(t_point));
	*so->collectible->tile_coors = (t_point){0, 3 * 16};
	so->collectible->img = create_img(so, (uint32_t[4]){TS, TS,
			so->collectible->tile_coors->x, so->collectible->tile_coors->y});
	so->enemy = malloc(sizeof(t_elem));
	if (so->enemy == NULL)
		return ;
	so->enemy->tile_coors = malloc(sizeof(t_point));
	*so->enemy->tile_coors = (t_point){0, 9 * 16};
	so->enemy->img = create_img(so, (uint32_t[4]){TS, TS,
			so->enemy->tile_coors->x, so->enemy->tile_coors->y});
}

mlx_image_t	*create_img(t_so *so, uint32_t crop[4])
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
	if (!img)
		ft_error();
	mlx_delete_texture(sheet);
	return (img);
}

void	draw_elems2(t_so *so, int i, int j)
{
	if (so->tab[i][j] == 'C')
		mlx_image_to_window(so->mlx, so->collectible->img, j * TS, i * TS);
	else if (so->tab[i][j] == 'P')
		mlx_image_to_window(so->mlx, so->d->img, j * TS, i * TS - so->d->of);
	else if (so->tab[i][j] == 'E')
		mlx_image_to_window(so->mlx, so->s->img, j * TS, i * TS - so->s->of);
	else if (so->tab[i][j] == 'M')
		mlx_image_to_window(so->mlx, so->enemy->img, j * TS, i * TS);
}

void	draw_elems(t_so *so)
{
	int		i;
	int		j;

	i = 0;
	init_elems(so);
	init_elems2(so);
	while (so->tab[++i])
	{
		j = 0;
		while (so->tab[i][++j])
		{
			if (so->tab[i][j] == 'C' || so->tab[i][j] == 'P' ||
					so->tab[i][j] == 'E'
					|| so->tab[i][j] == 'M' || so->tab[i][j])
				draw_elems2(so, i, j);
		}
	}
}
