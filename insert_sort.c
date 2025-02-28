/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seruff <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 15:33:39 by seruff            #+#    #+#             */
/*   Updated: 2025/02/26 15:57:17 by seruff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	give_index(List *list)
{
	int		i;
	Element	*current;

	i = 1;
	current = list->first;
	while (i < (count_elements(list) + 1))
	{
		current->index = i;
		i++;
		current = current->next;
	}
}

static void	copy_index(List *list, List *temp)
{
	Element	*curlist;
	Element	*curtemp;

	curlist = list->first;
	curtemp = temp->first;
	while (curlist->next != list->first)
	{
		if (curlist->value == curtemp->value)
		{
			if (curlist->index != 0)
				curlist = curlist->next;
			else
			{	
				curlist->index = curtemp->index;
				curlist = list->first;
			}
		}
		curtemp = curtemp->next;
	}
	curtemp = temp->first;
	while (curlist->index == 0)
	{
		if (curlist->value == curtemp->value)
			curlist->index = curtemp->index;
		curtemp = curtemp->next;
	}
}

void	insert_sort(List *list)
{
	int		tmp;
	List	*temp;
	Element	*current;

	temp = copy_list(list);
	if (!temp)
		return ;
	current = temp->first;
	while (current->next != temp->first)
	{
		if (current->value > current->next->value)
		{
			tmp = current->value;
			current->value = current->next->value;
			current->next->value = tmp;
			current = temp->first;
		}	
		else
			current = current->next;
	}
	give_index(temp);
	copy_index(list, temp);
	free_list(temp);
	free(temp);
}
