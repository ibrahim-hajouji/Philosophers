/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 05:46:20 by ihajouji          #+#    #+#             */
/*   Updated: 2024/06/25 11:36:48 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_table
{
	pthread_mutex_t	*forks;
	int				philos_nbr;
	long long		tt_die;
	long long		tt_eat;
	long long		tt_sleep;
	long long		meals_nbr;
	long long		time_start;
	pthread_mutex_t	write;
	pthread_mutex_t	death;
	pthread_mutex_t	death_status_mutex;
	int				death_status;
}					t_table;

typedef struct s_philo
{
	int				id;
	long			meals_eaten;
	int				full;
	long long		last_meal;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;
	pthread_t		thread;
	t_table			*table;
}					t_philo;

//------------------------- ERRORS HANDLING -------------------------//
void				destroy(t_table *table, int j);
void				destroy2(t_philo *philos, t_table *table, int j);

//------------------------- PARSING & INITIALIZING -------------------------//
int					ft_atoi(char *str);
int					parsing(t_table *table, char **av, int ac);
int					init_forks(t_table *table);
long long			get_time(void);
int					print(char *msg, t_philo *philo);

//------------------------- SIMULATION & ACTIONS -------------------------//
void				eating(t_philo *philo);
void				sleeping(t_philo *philo);
void				thinking(t_philo *philo);
int					simulation(t_philo *philos, t_table *table);

//------------------------- CHECKING PHILO STATE -------------------------//
int					check_philo(t_philo *philo);
int					dead_method(t_philo *philo, char m);
#endif