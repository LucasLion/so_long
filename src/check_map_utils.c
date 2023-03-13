/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llion <llion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 14:14:21 by llion             #+#    #+#             */
/*   Updated: 2023/01/20 12:10:14 by llion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	get_map_height(t_so *so)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = so->map;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

int	check_map_rect(t_so *so)
{
	int		len;
	t_list	*tmp;

	tmp = so->map;
	so->width = ft_strlen(tmp->content);
	while (tmp)
	{
		len = ft_strlen(tmp->content);
		if (len != so->width)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	check_left_right(char **tab)
{
	int	i;
	int	j;

	j = 0;
	while (tab[j])
	{
		i = 0;
		if (tab[j][i] != '1')
			return (0);
		while (tab[j][i] != '\0')
			i++;
		i--;
		if (tab[j][i] != '1')
			return (0);
		j++;
	}
	return (1);
}

int	check_top_bottom(char **tab)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (tab[j][i] != '\0')
	{
		if (tab[j][i] != '1')
			return (0);
		i++;
	}
	while (tab[j])
		j++;
	j--;
	i = 0;
	while (tab[j][i] != '\0')
	{
		if (tab[j][i] != '1')
			return (0);
		i++;
	}
	return (1);
}
