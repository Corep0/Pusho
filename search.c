/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seruff <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 15:21:36 by seruff            #+#    #+#             */
/*   Updated: 2025/02/26 15:50:24 by seruff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	search_min(List *list)
{
	int		min;
	Element	*current;

	current = list->first;
	if (!list)
		return (0);
	if (current != NULL)
		min = current->index;
	current = current->next;
	while (current != list->first)
	{
		if (min > current->index)
			min = current->index;
		current = current->next;
	}
	if (min > current->index)
		min = current->index;
	return (min);
}

int	search_max(List *list)
{
	int		max;
	Element	*current;

	if (!list)
		return (0);
	current = list->first;
	if (current != NULL)
		max = list->first->index;
	current = current->next;
	while (current != list->first)
	{
		if (max < current->index)
			max = current->index;
		current = current->next;
	}
	if (max < current->index)
		max = current->index;
	return (max);
}
