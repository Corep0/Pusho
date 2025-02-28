/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seruff <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:47:22 by seruff            #+#    #+#             */
/*   Updated: 2025/02/26 15:50:50 by seruff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	swap(List *list)
{
	int		tmp;	
	Element	*head;
	Element	*second;

	if (list->first == NULL || list->first->next == list->first)
		return ;
	head = list->first;
	second = list->first->next;
	tmp = head->value;
	head->value = second->value;
	second->value = tmp;
	tmp = head->index;
	head->index = second->index;
	second->index = tmp;
}

int	swap_sa(List *list)
{
	swap(list);
	ft_printf("sa\n");
	return (0);
}

int	swap_sb(List *list)
{
	swap(list);
	ft_printf("sb\n");
	return (1);
}

int	swap_ss(List *listA, List *listB)
{
	swap_sa(listA);
	swap_sb(listB);
	ft_printf("ss\n");
	return (2);
}
