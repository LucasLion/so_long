/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llion <llion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 13:33:41 by llion             #+#    #+#             */
/*   Updated: 2023/01/23 15:52:58 by llion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	*flood_fill(char **tab, t_point cur, t_point size, char to_fill)
{
	static int	objects[3];

	if ((tab[cur.y][cur.x] != 'E' && tab[cur.y][cur.x] != 'C'
			&& tab[cur.y][cur.x] != '0' && tab[cur.y][cur.x] != 'P')
		|| cur.x < 0 || cur.x >= size.x || cur.y < 0 || cur.y >= size.y)
		return (0);
	if (tab[cur.y][cur.x] == 'C')
		objects[0]++;
	if (tab[cur.y][cur.x] == 'E')
		objects[1]++;
	if (tab[cur.y][cur.x] == 'M')
		objects[2]++;
	tab[cur.y][cur.x] = '.';
	flood_fill(tab, (t_point){cur.x - 1, cur.y}, size, to_fill);
	flood_fill(tab, (t_point){cur.x, cur.y + 1}, size, to_fill);
	flood_fill(tab, (t_point){cur.x + 1, cur.y}, size, to_fill);
	flood_fill(tab, (t_point){cur.x, cur.y - 1}, size, to_fill);
	return ((int *)objects);
}
