/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llion <llion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 13:33:10 by llion             #+#    #+#             */
/*   Updated: 2023/01/23 18:00:11 by llion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_error(void)
{
	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

int	check_errors(char **tab)
{
	int	i;
	int	j;

	j = 0;
	while (tab[j])
	{
		i = 0;
		while (tab[j][i])
		{
			if (tab[j][i] != '1' && tab[j][i] != '0' && tab[j][i] != 'C'
				&& tab[j][i] != 'P' && tab[j][i] != 'E' && tab[j][i] != '\0'
				&& tab[j][i] != 'M' && tab[j][i] != '\n')
				return (0);
			i++;
		}
		j++;
	}
	return (1);
}

int	return_errors(t_so *so)
{
	char	**tab_cpy;

	tab_cpy = tabcpy(so);
	if (!so->top_bottom || !so->left_right || !so->rect
		|| so->objects[0] != so->item_num || so->item_num == 0
		|| so->exit > 1 || so->objects[1] != so->exit
		|| !check_errors(tab_cpy) || so->begin > 1)
	{
		free_tab(tab_cpy);
		return (1);
	}
	else
	{
		free_tab(tab_cpy);
		return (0);
	}
}

int	arg_check(char **argv)
{	
	char	*file;
	char	*ext;

	file = argv[1];
	ext = ft_strrchr(file, '.');
	if (ext && !ft_strncmp(ext, ".ber", ft_strlen(file)))
		return (1);
	else
	{
		ft_printf("Error\n");
		ft_printf("le fichier n'a pas la bonne extension\n");
		return (0);
	}
}

void	print_errors(t_so *so)
{
	char	**tab_cpy;

	tab_cpy = tabcpy(so);
	if (!so->top_bottom)
		ft_printf("Error\nCarte ouverte sur le dessus ou le dessous\n");
	if (!so->left_right)
		ft_printf("Error\nCarte ouverte sur un des cotés\n");
	if (!so->rect)
		ft_printf("Error\nCarte non rectangulaire\n");
	if (so->objects[0] != so->item_num)
		ft_printf("Error\nObjets inaccessibles\n");
	if (so->item_num == 0)
		ft_printf("Error\nPas de collectibles\n");
	if (so->exit > 1)
		ft_printf("Error\nPlusieurs sorties\n");
	if (so->exit < 1)
		ft_printf("Error\nPas de sortie\n");
	if (so->objects[1] != so->exit)
		ft_printf("Error\nSortie inaccessible\n");
	if (!check_errors(tab_cpy))
		ft_printf("Error\nCaractères idésirables\n");
	if (so->begin > 1)
		ft_printf("Error\nPlusieurs entrées\n");
	free_tab(tab_cpy);
}
