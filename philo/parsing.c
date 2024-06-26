/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 12:38:30 by ihajouji          #+#    #+#             */
/*   Updated: 2024/06/24 17:07:15 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	parsing(t_table *table, char **av, int ac)
{
	int	i;

	i = 0;
	if (ac < 5 || ac > 6)
		return (printf("Wrong number of arguments\n"), 1);
	table->philos_nbr = ft_atoi(av[1]);
	table->tt_die = ft_atoi(av[2]);
	table->tt_eat = ft_atoi(av[3]) * 1000;
	table->tt_sleep = ft_atoi(av[4]) * 1000;
	if (table->philos_nbr == -1 || table->philos_nbr == 0 || table->tt_die == -1
		|| table->tt_eat == -1000 || table->tt_sleep == -1000)
		return (printf("Bad Arguments\n"), 1);
	if (ac == 6)
	{
		table->meals_nbr = ft_atoi(av[5]);
		if (table->meals_nbr == -1)
			return (printf("Bad Arguments\n"), 1);
	}
	else
		table->meals_nbr = -1;
	table->death_status = 0;
	return (0);
}
