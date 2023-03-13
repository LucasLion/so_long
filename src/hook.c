/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llion <llion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:33:26 by llion             #+#    #+#             */
/*   Updated: 2023/01/25 13:05:15 by llion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	hook(void *param)
{
	t_so		*so;
	static int	x = 0;

	so = param;
	if (so->p->state == 0 && x >= 6)
		x = 0;
	else if (so->p->state == 1 && x >= 4)
		x = 0;
	else if (so->p->state == 2 && x >= 6)
		x = 0;
	else if (so->p->state == 3 && x >= 4)
		x = 0;
	mlx_delete_image(so->mlx, so->p->img);
	draw_player(so, (x / 2));
	x++;
	if ((int)so->objects_picked == (int)so->objects[0] && \
			so->tab[so->p->pos->y / 16][so->p->pos->x / 16] == 'E')
	{
		ft_printf("WIN\n");
		system("leaks so_long");
		mlx_terminate(so->mlx);
		exit(0);
	}
}

void	manage_player_movement(t_so *so, int n)
{
	if (n == 1)
	{
		so->p->pos->y -= TS;
		so->p->state = 1;
	}
	if (n == 2)
	{
		so->p->pos->y += TS;
		so->p->state = 3;
	}
	if (n == 3)
	{
		so->p->pos->x -= TS;
		so->p->state = 0;
	}
	if (n == 4)
	{
		so->p->pos->x += TS;
		so->p->state = 2;
	}
	so->steps++;
	ft_printf("Steps: %d\n", so->steps);
	mlx_delete_image(so->mlx, so->p->img);
	draw_player(so, 0);
	collide_item(so);
}

void	move_player(mlx_key_data_t keydata, void *param)
{
	t_so			*so;
	char			*score;
	mlx_instance_t	*i;

	so = param;
	i = so->p->img->instances;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(so->mlx);
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS
		&& so->tab[(i[0].y - 16) / 16][i[0].x / 16] != '1')
		manage_player_movement(so, 1);
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS
		&& so->tab[(i[0].y + 16) / 16][i[0].x / 16] != '1')
		manage_player_movement(so, 2);
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS
		&& so->tab[i[0].y / 16][(i[0].x - 16) / 16] != '1')
		manage_player_movement(so, 3);
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS
		&& so->tab[i[0].y / 16][(i[0].x + 16) / 16] != '1')
		manage_player_movement(so, 4);
	mlx_delete_image(so->mlx, so->text);
	score = ft_itoa(so->steps);
	so->text = mlx_put_string(so->mlx, score, 4, 4);
	free(score);
}

void	collide_item(void *param)
{
	t_so			*so;
	mlx_instance_t	*ins;
	int				i;

	so = param;
	i = 0;
	ins = so->p->img->instances;
	if (so->tab[ins[0].y / 16][ins[0].x / 16] == 'C')
	{
		so->objects_picked++;
		so->tab[ins[0].y / 16][ins[0].x / 16] = '0';
		while (i < so->item_num)
		{
			if (so->p->pos->x == so->collectible->img->instances[i].x
				&& so->p->pos->y == so->collectible->img->instances[i].y)
				so->collectible->img->instances[i].enabled = false;
			i++;
		}
	}
	else if (so->tab[ins[0].y / 16][ins[0].x / 16] == 'M')
	{
		ft_printf("MISS\n");
		mlx_terminate(so->mlx);
		exit(0);
	}
}
