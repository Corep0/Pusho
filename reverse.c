/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seruff <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:47:44 by seruff            #+#    #+#             */
/*   Updated: 2025/02/26 15:49:31 by seruff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	reverse(List *list)
{
	Element	*current;

	if (list == NULL || list->first == NULL || list->first->next == NULL)
		return ;
	current = list->first;
	while (current->next != list->first)
		current = current->next;
	list->first = current;
}

int	reverse_rra(List *listA)
{
	reverse(listA);
	ft_putendl_fd("rra", 1);
	return (0);
}

int	reverse_rrb(List *listB)
{
	reverse(listB);
	ft_putendl_fd("rrb", 1);
	return (1);
}

int	reverse_rrr(List *listA, List *listB)
{
	reverse(listA);
	reverse(listB);
	ft_putendl_fd("rrr", 1);
	return (2);
}
