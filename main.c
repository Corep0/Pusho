/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seruff <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 08:56:11 by seruff            #+#    #+#             */
/*   Updated: 2025/02/26 15:47:42 by seruff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static	void	free_all(List *a, List *b)
{
	free_list(a);
	free(a);
	free_list(b);
	free(b);
}

int	main(int ac, char **av)
{
	List	*a;
	List	*b;

	if (ac < 2)
		return (1);
	a = init_list();
	b = init_list();
	if (init(a, ac, av) == 0)
	{
		ft_printf("Error\n");
		free_all(a, b);
		return (1);
	}
	insert_sort(a);
	if (is_sorted(a) == 1)
		sort(a, b);
	free_all(a, b);
	return (0);
}
