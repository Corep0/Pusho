/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seruff <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:47:36 by seruff            #+#    #+#             */
/*   Updated: 2025/02/26 15:50:02 by seruff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rotate(List *list)
{
	Element	*current;

	if (list == NULL || list->first == NULL || list->first->next == NULL)
		return ;
	current = list->first;
	while (current->next != list->first)
		current = current->next;
	current->next = list->first;
	list->first = list->first->next;
	current->next->next = list->first;
}

int	rotate_ra(List *list)
{
	rotate(list);
	ft_putendl_fd("ra", 1);
	return (0);
}

int	rotate_rb(List *temp)
{
	rotate(temp);
	ft_putendl_fd("rb", 1);
	return (0);
}

int	rotate_rr(List *list, List *temp)
{
	rotate(list);
	rotate(temp);
	ft_putendl_fd("rr", 1);
	return (0);
}
