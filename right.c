/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   right.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seruff <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 15:18:29 by seruff            #+#    #+#             */
/*   Updated: 2025/02/26 15:49:48 by seruff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	is_sorted(List *list)
{
	int		i;
	Element	*current;

	current = list->first;
	i = 1;
	while (current->next != list->first)
	{
		if (current->index == i)
			i++;
		current = current->next;
	}
	if (i == search_max(list))
		return (0);
	return (1);
}
