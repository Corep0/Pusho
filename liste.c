/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liste.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seruff <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 08:17:27 by seruff            #+#    #+#             */
/*   Updated: 2025/02/26 15:44:50 by seruff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

Element	*create_element(int value)
{
	Element	*newelement;

	newelement = (Element *)malloc(sizeof(Element));
	if (!newelement)
		exit(EXIT_FAILURE);
	newelement->value = value;
	newelement->index = 0;
	newelement->next = NULL;
	newelement->prev = NULL;
	return (newelement);
}

List	*init_list(void)
{
	List	*list;

	list = (List *)malloc(sizeof(*list));
	if (list == NULL)
		exit(EXIT_FAILURE);
	list->first = NULL;
	return (list);
}

void	add_element(List *list, int value)
{
	Element	*newelement;
	Element	*current;

	newelement = create_element(value);
	if (!list->first)
	{
		list->first = newelement;
		newelement->next = newelement;
		newelement->prev = newelement;
	}
	else
	{
		current = list->first;
		while (current->next != list->first)
			current = current->next;
		current->next = newelement;
		newelement->prev = current;
		list->first->prev = newelement;
		newelement->next = list->first;
		list->first = newelement;
	}
}

List	*copy_list(List *list)
{
	List	*tempo;
	Element	*current;

	tempo = init_list();
	if (!tempo)
		exit(EXIT_FAILURE);
	current = list->first;
	while (current->next != list->first)
	{
		add_element(tempo, current->value);
		current = current->next;
	}
	add_element(tempo, current->value);
	while (peek_top_list(list) != peek_top_list(tempo))
		reverse(tempo);
	return (tempo);
}

int	count_elements(List *list)
{
	int		count;
	Element	*current;

	count = 0;
	current = list->first;
	if (list->first == NULL)
		return (0);
	if (list->first != NULL)
		count++;
	while (current->next != list->first)
	{
		current = current->next;
		count++;
	}
	return (count);
}
