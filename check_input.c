/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seruff <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 12:32:24 by seruff            #+#    #+#             */
/*   Updated: 2025/02/26 15:35:44 by seruff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	is_numb(char *av)
{
	int	i;

	i = 0;
	if (ft_signe(av[i]))
		i++;
	if (av[i] == '\0')
		return (0);
	while (av[i])
	{
		if (!ft_isdigit(av[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	duplica(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = i + 1;
		while (av[j])
		{
			if (ft_atol(av[i]) - ft_atol(av[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	multi_zero(char *av)
{
	int	i;

	i = 0;
	if (ft_signe(av[i]))
		i++;
	while (av[i] && av[i] == '0')
		i++;
	if (av[i])
		return (0);
	return (1);
}

int	good_input(char **av)
{
	int	i;
	int	nb_zero;

	i = 1;
	nb_zero = 0;
	while (av[i])
	{
		if (is_numb(av[i]) == 0)
			return (0);
		if (ft_atol(av[i]) > INT_MAX || ft_atol(av[i]) < INT_MIN)
			return (0);
		nb_zero += multi_zero(av[i]);
		i++;
	}
	if (nb_zero > 1)
		return (0);
	if (duplica(av) == 1)
		return (0);
	return (1);
}
