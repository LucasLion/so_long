/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llion <llion@student.42mulhouse.fr >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 15:04:24 by llion             #+#    #+#             */
/*   Updated: 2023/01/20 12:07:04 by llion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*current_lst;

	if (*lst == NULL)
		*lst = new;
	else
	{
		current_lst = ft_lstlast(*lst);
		current_lst->next = new;
	}
}
