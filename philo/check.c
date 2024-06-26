/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 11:18:01 by ihajouji          #+#    #+#             */
/*   Updated: 2024/06/26 11:50:01 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_meals(t_philo *philo)
{
	if ((philo->meals_eaten >= philo->table->meals_nbr)
		&& (philo->table->meals_nbr != -1))
		philo->full = 1;
	return ;
}

int	check_full(t_philo *philo)
{
	int	j;

	j = -1;
	while (++j < philo->table->philos_nbr)
	{
		if ((&philo[j])->full != 1)
			return (0);
	}
	return (1);
}

void	check_dead(t_philo *philo)
{
	if ((get_time() - philo->last_meal) > (philo)->table->tt_die)
	{
		pthread_mutex_lock(&philo->table->death_status_mutex);
		philo->table->death_status = 1;
		pthread_mutex_unlock(&philo->table->death_status_mutex);
	}
	return ;
}

int	check_philo(t_philo *philo)
{
	int	i;

	i = 0;
	while (1)
	{
		pthread_mutex_lock(&philo->table->death);
		philo_meals(&philo[i]);
		if (check_full(philo) == 1)
			return (1);
		check_dead(&philo[i]);
		pthread_mutex_lock(&philo->table->death_status_mutex);
		if ((&philo[i])->table->death_status == 1)
		{
			pthread_mutex_unlock(&philo->table->death_status_mutex);
			pthread_mutex_lock(&philo->table->write);
			printf("%lld %d died\n", (get_time() - philo->table->time_start),
				(&philo[i])->id);
			return (1);
		}
		pthread_mutex_unlock(&philo->table->death_status_mutex);
		i = (i + 1) % philo->table->philos_nbr;
		pthread_mutex_unlock(&philo->table->death);
	}
	return (0);
}
