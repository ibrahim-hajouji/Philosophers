/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 06:09:53 by ihajouji          #+#    #+#             */
/*   Updated: 2024/06/24 11:30:35 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(char *str)
{
	int		i;
	long	number;

	i = 0;
	number = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			return (-1);
		i++;
	}
	if (str[i] == '\0')
		return (-1);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (-1);
		else
			number = number * 10 + (str[i++] - '0');
	}
	if (number > INT_MAX)
		return (-1);
	return (number);
}

long long	get_time(void)
{
	struct timeval	t;
	long long		msc;

	gettimeofday(&t, NULL);
	msc = t.tv_sec * 1000 + t.tv_usec / 1000;
	return (msc);
}
