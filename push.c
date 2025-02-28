/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seruff <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:47:28 by seruff            #+#    #+#             */
/*   Updated: 2025/02/24 15:38:39 by seruff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	push(List *src, List *dest)
{
	Element *pushed;
	Element	*current;

	if (src->first == NULL)
		return;
	pushed = src->first;
	if (src->first->next == src->first)
		src->first = NULL;
	else
	{
		current = src->first;
		while (current->next != src->first)
			current = current->next;
		current->next = src->first->next;
		src->first = src->first->next;
	}
	if (dest->first == NULL)
	{
		dest->first = pushed;
		pushed->next = pushed;	
	}
	else
	{
		Element *current = dest->first;
		while (current->next != dest->first)
			current = current->next;
		current->next = pushed;
		pushed->next = dest->first;
		dest->first = pushed;
	}
}

int	push_pa(List *src, List *dest)
{
	push(src, dest);
	ft_printf("pb\n");
	return (0);	
}

int	push_pb(List *src, List *dest)
{
	push(dest, src);
	ft_printf("pa\n");
	return (1);
}
