/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 13:28:16 by ihajouji          #+#    #+#             */
/*   Updated: 2024/06/26 19:44:24 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_actions(t_table *table, t_philo *philos)
{
	if (pthread_mutex_init(&(table->write), NULL))
		return (destroy2(philos, table, 0), 1);
	if (pthread_mutex_init(&(table->death_status_mutex), NULL))
	{
		pthread_mutex_destroy(&(table->write));
		return (destroy2(philos, table, 0), 1);
	}
	if (pthread_mutex_init(&(table->death), NULL))
	{
		pthread_mutex_destroy(&(table->write));
		return (destroy2(philos, table, 0), 1);
	}
	return (0);
}

void	*routine(void *philo_ptr)
{
	t_philo	*philo;

	philo = (t_philo *)philo_ptr;
	if (philo->id % 2 == 0 || philo ->id == philo->table->philos_nbr)
	{
		thinking(philo);
		usleep(philo->table->tt_eat);
	}
	while (1)
	{
		eating(philo);
		sleeping(philo);
		thinking(philo);
	}
	return (NULL);
}

int	simulation(t_philo *philos, t_table *table)
{
	int	i;

	i = 0;
	if (init_actions(table, philos))
		return (1);
	table->time_start = get_time();
	while (i < table->philos_nbr)
		philos[i++].last_meal = table->time_start;
	i = 0;
	while (i < table->philos_nbr)
	{
		if (pthread_create(&(philos[i].thread), NULL, &routine, &philos[i]))
			return (destroy2(philos, table, 0), 1);
		i += 1;
		usleep(5);
	}
	return (0);
}
