/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 06:00:52 by ihajouji          #+#    #+#             */
/*   Updated: 2024/06/26 11:42:02 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_init(t_philo *philos, t_table *table)
{
	int	i;

	i = 0;
	while (i < table->philos_nbr)
	{
		philos[i].id = i + 1;
		philos[i].meals_eaten = 0;
		philos[i].right_fork = &table->forks[i];
		philos[i].left_fork = &table->forks[(i + 1) % table->philos_nbr];
		philos[i].table = table;
		philos[i].full = 0;
		i++;
	}
}

void	detach_destroy(t_philo *philos, t_table *table)
{
	int	i;

	i = 0;
	while (i < table->philos_nbr)
		pthread_detach(philos[i++].thread);
	i = 0;
	while (i < table->philos_nbr)
	{
		pthread_mutex_destroy(&table->forks[i]);
		i++;
	}
	return ;
}

int	main(int ac, char **av)
{
	t_table	*table;
	t_philo	*philos;

	table = malloc(sizeof(t_table));
	if (!table)
		return (printf("Failed to allocate the table\n"));
	if (parsing(table, av, ac))
		return (free(table), 1);
	init_forks(table);
	philos = malloc(sizeof(t_philo) * table->philos_nbr);
	if (!philos)
	{
		destroy(table, 1);
		return (free(table), 1);
	}
	philo_init(philos, table);
	simulation(philos, table);
	check_philo(philos);
	detach_destroy(philos, table);
	free(table->forks);
	free(philos);
	free(table);
	return (0);
}
