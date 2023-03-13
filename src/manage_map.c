/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llion <llion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 13:31:16 by llion             #+#    #+#             */
/*   Updated: 2023/01/23 15:54:11 by llion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_map(t_so *so)
{
	so->start = malloc(sizeof(t_point));
	if (so->start == NULL)
		return ;
	so->objects_picked = 0;
	so->objects = 0;
	so->steps = 0;
	so->start->x = 0;
	so->start->y = 0;
	so->width = 0;
	so->height = 0;
	so->rect = 0;
	so->top_bottom = 0;
	so->left_right = 0;
	so->objects = 0;
	so->item_num = 0;
	so->begin = 0;
	so->exit = 0;
	so->entrance = 0;
	so->sheet = "./spritesheets/sheet.png";
}

t_list	*fill_map(int fd)
{
	t_list	*new;
	t_list	*head;
	char	*line;

	head = NULL;
	while (1)
	{
		new = malloc(sizeof(t_list));
		if (new == NULL)
			return (NULL);
		line = get_next_line(fd);
		if (line == NULL)
		{
			free(new);
			break ;
		}
		new->content = line;
		new->next = NULL;
		ft_lstadd_back(&head, new);
	}
	return (head);
}

char	**fill_tab_with_list(t_so *so)
{
	char	**tab;
	char	**head;
	t_list	*head_list;

	head_list = so->map;
	tab = malloc(sizeof(char *) * (so->height + 1));
	if (tab == NULL)
		return (NULL);
	head = tab;
	while (head_list)
	{
		*tab = head_list->content;
		head_list = head_list->next;
		tab++;
	}
	*tab = 0;
	return (head);
}
