/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seruff <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 09:02:47 by seruff            #+#    #+#             */
/*   Updated: 2025/02/26 14:44:52 by seruff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_small(List *list)
{
	int	one;
	int	two;
	int	three;

	one = list->first->index;
	two = list->first->next->index;
	three = list->first->next->next->index;
	if (one > two && two < three && three < one)
		rotate_ra(list);
	else if (one > two && two < three && three > one)
		swap_sa(list);
	else if (one > two && two > three && three < one)
	{
		swap_sa(list);
		reverse_rra(list);
	}
	else if (one < two && two > three && three < one)
		reverse_rra(list);
	else if (one < two && two > three && three > one)
	{
		swap_sa(list);
		rotate_ra(list);
	}
}

void	sort_four(List *list, List *temp)
{
	move_to_top(list, search_min(list), 1);
	push_pa(list, temp);
	sort_small(list);
	push_pb(list, temp);
}

void	sort_five(List *list, List *temp)
{
	move_to_top(list, search_min(list), 1);
	push_pa(list, temp);
	move_to_top(list, search_min(list), 1);
	push_pa(list, temp);
	sort_small(list);
	push_pb(list, temp);
	push_pb(list, temp);
}

void	sort(List *list, List *temp)
{
	int	size;

	size = count_elements(list);
	if (size == 2)
		swap_sa(list);
	else if (size == 3)
		sort_small(list);
	else if (size == 4)
		sort_four(list, temp);
	else if (size == 5)
		sort_five(list, temp);
	else
		sort_more(list, temp);
}
