/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llion <llion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 13:24:31 by llion             #+#    #+#             */
/*   Updated: 2023/01/23 16:34:48 by llion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	**tabcpy(t_so *so)
{
	char	**cpy;
	int		i;

	i = 0;
	cpy = malloc(sizeof(char *) * (so->height + 1));
	if (cpy == NULL)
		return (NULL);
	while (so->tab[i])
	{
		cpy[i] = malloc(sizeof(char) * (ft_strlen(so->tab[i]) + 1));
		if (cpy[i] == NULL)
			return (NULL);
		ft_strlcpy(cpy[i], so->tab[i], ft_strlen(so->tab[i]) + 1);
		i++;
	}
	cpy[i] = 0;
	return (cpy);
}
