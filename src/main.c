/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llion <llion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 16:55:38 by llion             #+#    #+#             */
/*   Updated: 2023/01/24 16:35:36 by llion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	loop_game(t_so *so)

{
	so->mlx = mlx_init(so->width * 16, so->height * 16, "SO_LONG", true);
	if (!so->mlx)
		return (EXIT_FAILURE);
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	draw_tiles(so);
	draw_elems(so);
	create_player(so);
	draw_player(so, 2);
	so->text = mlx_put_string(so->mlx, "0", 4, 4);
	mlx_key_hook(so->mlx, &move_player, so);
	mlx_loop_hook(so->mlx, &hook, so);
	mlx_loop(so->mlx);
	return (EXIT_SUCCESS);
}

int	main(int argc, char *argv[])
{
	int		fd;
	t_so	*so;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (!arg_check(argv))
			return (1);
		so = malloc(sizeof(t_so));
		if (so == NULL)
			return (0);
		init_map(so);
		so->map = fill_map(fd);
		if (check_map(so))
			return (1);
		loop_game(so);
		mlx_terminate(so->mlx);
	}
	else
		ft_printf("Error\nUn seul argument svp\n");
	system("leaks so_long");
	return (0);
}
