/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seruff <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 14:34:08 by seruff            #+#    #+#             */
/*   Updated: 2025/02/26 15:36:13 by seruff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
/*
int	fill_list_from_string(List *list, char **av)
{
	int		j;
	int		count;
	char	**input;

	count = count_words(av[1], ' ');
	j = count;
	input = ft_split(av[1], ' ');
	if (good_input(input) == 0)
		return (0);
	while (count--)
		add_element(list, atoi(input[count]));
	while (j--)
		free(input[j]);
	free(input);
	return (1);
}
*/
void	fill_list(List *list, int ac, char **av)
{
	int	i;

	i = ac - 1;
	while (i > 0)
	{
		add_element(list, atoi(av[i]));
		i--;
	}
}

int	init(List *list, int ac, char **av)
{
/*	if (ac == 2)
	{
		if (fill_list_from_string(list, av) == 0)
			return (0);
	}*/
	if (ac > 2 && good_input(av) == 1)
		fill_list(list, ac, av);
	else
		return (0);
	return (1);
}
