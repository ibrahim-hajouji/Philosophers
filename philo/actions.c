/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 17:12:39 by ihajouji          #+#    #+#             */
/*   Updated: 2024/06/25 13:25:15 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	thinking(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->write);
	printf("%lld %d is thinking\n", (get_time() - philo->table->time_start),
		philo->id);
	pthread_mutex_unlock(&philo->table->write);
}

void	sleeping(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->write);
	printf("%lld %d is sleeping\n", (get_time() - philo->table->time_start),
		philo->id);
	pthread_mutex_unlock(&philo->table->write);
	usleep(philo->table->tt_sleep);
}

int	print(char *msg, t_philo *philo)
{
	pthread_mutex_lock(&philo->table->write);
	printf("%lld %d %s\n",
		(get_time() - philo->table->time_start),
		philo->id, msg);
	pthread_mutex_unlock(&philo->table->write);
	return (0);
}

void	eating(t_philo *philo)
{
	pthread_mutex_lock(philo->right_fork);
	print("has taken a fork", philo);
	pthread_mutex_lock(philo->left_fork);
	print("has taken a fork", philo);
	print("is eating", philo);
	pthread_mutex_lock(&philo->table->death);
	philo->last_meal = get_time();
	pthread_mutex_unlock(&philo->table->death);
	usleep(philo->table->tt_eat);
	pthread_mutex_lock(&philo->table->death);
	philo->meals_eaten++;
	pthread_mutex_unlock(&philo->table->death);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}
