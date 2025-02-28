/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushed_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seruff <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 13:45:25 by seruff            #+#    #+#             */
/*   Updated: 2025/02/26 15:49:13 by seruff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_lstschr(List *list, int search)
{
	Element	*current;

	current = list->first;
	while (current->next != list->first)
	{
		if (current->index <= search)
			return (1);
		current = current->next;
	}
	return (0);
}

static	int	top_next(List *list, int search)
{
	int		i;
	Element	*current;

	i = 1;
	current = list->first;
	while (current->next != list->first)
	{
		if (current->index <= search)
			break ;
		i++;
		current = current->next;
	}
	i--;
	return (i);
}

static	int	bot_next(List *list, int search)
{
	int		j;
	Element	*current;

	current = list->first;
	j = 1;
	while (current->prev != list->first)
	{
		if (current->index <= search)
			break ;
		j++;
		current = current->prev;
	}
	j--;
	return (j);
}

static void	move_next_ele(List *list, int median)
{
	int	rev;
	int	rot;

	rev = bot_next(list, median);
	rot = top_next(list, median);
	if (rot < rev)
	{
		while (rot != 0)
		{
			rotate_ra(list);
			rot--;
		}
	}
	else
	{
		while (rev != 0)
		{
			reverse_rra(list);
			rev--;
		}
	}
}

void	move_in_b(List *list, List *temp, int median, int mid_median)
{
	Element	*current;

	current = list->first;
	if (current->index <= median)
	{
		push_pa(list, temp);
		if (current->index <= mid_median)
			rotate_rb(temp);
	}
	else
		move_next_ele(list, median);
}
