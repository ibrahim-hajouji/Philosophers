/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 12:57:56 by ihajouji          #+#    #+#             */
/*   Updated: 2024/06/19 18:06:21 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_forks(t_table *table)
{
	int	i;

	i = 0;
	table->forks = malloc(sizeof(pthread_mutex_t) * table->philos_nbr);
	if (!table->forks)
		return (printf("Failed to allocate the forks\n"), 1);
	while (i < table->philos_nbr)
	{
		if (pthread_mutex_init(&(table->forks[i]), NULL))
		{
			while (i >= 0)
				pthread_mutex_destroy(&(table->forks[--i]));
			free(table->forks);
			return (printf("Failed to intialize a mutex\n"), 1);
		}
		i++;
	}
	return (0);
}
