/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_more.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seruff <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 13:01:01 by seruff            #+#    #+#             */
/*   Updated: 2025/02/26 09:54:00 by seruff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static	void	pushed_to_b(List *list, List *temp)
{
	int	median;
	int	mid_median;

	median = (search_min(list) + search_max(list)) / 3;
	mid_median = (median + search_min(list)) / 2;
	while (count_elements(list) > 4)
	{
		while (ft_lstschr(list, median) == 1)
			move_in_b(list, temp, median, mid_median);
		median = (search_min(list) + search_max(list)) / 2;
		mid_median = (median + search_min(list)) / 2;
	}
	while (count_elements(list) != 0)
		push_pa(list, temp);
}

static	void	pushed_back_to_a(List *list, List *temp)
{
	while (count_elements(temp) != 0)
	{
		move_to_top(temp, search_max(temp), 2);
		push_pb(list, temp);
	}
}

void	sort_more(List *list, List *temp)
{
	pushed_to_b(list, temp);
	pushed_back_to_a(list, temp);
}
