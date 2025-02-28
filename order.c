/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seruff <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 14:56:16 by seruff            #+#    #+#             */
/*   Updated: 2025/02/26 15:48:09 by seruff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	peek_top_list(List *list)
{
	if (count_elements(list) < 1)
		return (-1);
	return (list->first->index);
}

int	peek_bot_list(List *list)
{
	if (count_elements(list) < 1)
		return (-1);
	return (list->first->prev->index);
}

int	r_or_rr(List *list, int index)
{
	int		r;
	Element	*current;

	r = 0;
	current = list->first;
	while (current->index != index)
	{
		r++;
		current = current->next;
	}
	if (r >= (count_elements(list) / 2))
		return (1);
	return (0);
}

static	void	do_r_or_rr(List *list, int index, int ab)
{
	int	move;

	move = r_or_rr(list, index);
	while (list->first->index != index)
	{
		if (move == 1 && ab == 1)
			reverse_rra(list);
		else if (move == 1 && ab == 2)
			reverse_rrb(list);
		else if (move == 0 && ab == 1)
			rotate_ra(list);
		else if (move == 0 && ab == 2)
			rotate_rb(list);
	}
}

void	move_to_top(List *list, int index, int ab)
{
	Element	*current;

	current = list->first;
	if (current->index == index)
		return ;
	do_r_or_rr(list, index, ab);
}
