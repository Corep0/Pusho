/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liste2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seruff <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 09:09:46 by seruff            #+#    #+#             */
/*   Updated: 2025/02/26 15:45:16 by seruff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	free_list(List *list)
{
	Element	*current;
	Element	*temp;

	if (!list->first)
		return ;
	current = list->first;
	temp = NULL;
	while (current->next != list->first)
	{
		temp = current;
		current = current->next;
		free(temp);
	}
	if (current != list->first)
	{
		temp = current;
		current = current->next;
		free(temp);
	}
	list->first = NULL;
}
