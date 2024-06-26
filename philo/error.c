/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 06:02:43 by ihajouji          #+#    #+#             */
/*   Updated: 2024/06/24 11:30:04 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	destroy(t_table *table, int j)
{
	int	i;

	i = 0;
	while (i < table->philos_nbr)
		pthread_mutex_destroy(&(table->forks[i++]));
	free(table->forks);
	if (j == 1)
		printf("Failed to allocate the philos\n");
}

void	destroy2(t_philo *philos, t_table *table, int j)
{
	free(philos);
	destroy(table, 0);
	free(table);
	if (j == 1)
		printf("Failed to create a thread\n");
}
