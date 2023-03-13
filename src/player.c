/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llion <llion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 19:14:46 by llion             #+#    #+#             */
/*   Updated: 2023/01/23 17:39:32 by llion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	create_player(t_so *so)
{
	int	i;
	int	j;

	so->p = malloc(sizeof(t_player));
	so->p->tile_coors = malloc(sizeof(t_point));
	so->p->tile_coors->x = 0;
	so->p->tile_coors->y = 0;
	so->p->state = 1;
	so->p->pos = malloc(sizeof(t_point));
	i = 0;
	while (so->tab[i])
	{
		j = 0;
		while (so->tab[i][j])
		{
			if (so->tab[i][j] == 'P')
			{
				so->p->pos->x = j * TS;
				so->p->pos->y = i * TS;
			}
			j++;
		}
		i++;
	}
}

void	draw_player(t_so *so, int x)
{
	if (so->p->state == 0)
		*so->p->tile_coors = (t_point){x * 16, 4 * 16};
	else if (so->p->state == 1)
		*so->p->tile_coors = (t_point){x * 16, 8 * 16};
	else if (so->p->state == 2)
		*so->p->tile_coors = (t_point){(x + 3) * 16, 4 * 16};
	else if (so->p->state == 3)
		*so->p->tile_coors = (t_point){x * 16, 7 * 16};
	so->p->img = init_tile(so, (uint32_t[4]){TS, TS, so->p->tile_coors->x,
			so->p->tile_coors->y});
	mlx_image_to_window(so->mlx, so->p->img, so->p->pos->x, so->p->pos->y);
}
