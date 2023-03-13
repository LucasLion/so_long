/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llion <llion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 13:31:49 by llion             #+#    #+#             */
/*   Updated: 2023/01/23 16:34:47 by llion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	get_start_and_count_elems(t_so *so)
{
	int	i;
	int	j;

	j = 0;
	while (so->tab[j])
	{
		i = 0;
		while (so->tab[j][i])
		{
			if (so->tab[j][i] == 'P')
			{
				so->start->x = i;
				so->start->y = j;
				so->begin++;
			}
			if (so->tab[j][i] == 'C')
				so->item_num++;
			if (so->tab[j][i] == 'M')
				so->enemy_num++;
			if (so->tab[j][i] == 'E')
				so->exit++;
			i++;
		}
		j++;
	}
}

int	get_map_objects_and_values(t_so *so)
{
	char	**tab_cpy;
	t_point	start;
	t_point	size;

	so->height = get_map_height(so);
	so->rect = check_map_rect(so);
	so->tab = fill_tab_with_list(so);
	so->top_bottom = check_top_bottom(so->tab);
	so->left_right = check_left_right(so->tab);
	get_start_and_count_elems(so);
	if (so->begin < 1)
	{
		ft_printf("Erreur: pas d'entrée\n");
		return (1);
	}
	start.x = so->start->x;
	start.y = so->start->y;
	size.x = so->width;
	size.y = so->height;
	tab_cpy = tabcpy(so);
	so->objects = flood_fill(tab_cpy, start, size, so->tab[start.y][start.x]);
	free_tab(tab_cpy);
	return (0);
}

int	check_map(t_so *so)
{
	int	error;

	if (get_map_objects_and_values(so))
		return (0);
	print_errors(so);
	error = return_errors(so);
	return (error);
}
