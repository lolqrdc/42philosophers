/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spy_routine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 16:49:19 by lolq              #+#    #+#             */
/*   Updated: 2025/05/09 19:02:53 by loribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/* @brief le spy va surveiller si un philo est mort et/ou si il a 
assez mangé. */

void	*s_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		if (check_philo_death(philo) || philo_ate(philo) == FAIL)
			break ;
		ft_usleep(10);
	}
	return (NULL);
}

int	philo_is_dead(t_philo *philo, size_t time_to_die)
{
	pthread_mutex_lock(philo->meal_lock);
	if (get_current_time() - philo->last_meal >= time_to_die
		&& philo->eating == 0)
		return (pthread_mutex_unlock(philo->meal_lock), FAIL);
	pthread_mutex_unlock(philo->meal_lock);
	return (SUCCESS);
}

int	check_philo_death(t_philo *philos)
{
	int	i;

	i = 0;
	while (i < philos[0].nb_philos)
	{
		if (philo_is_dead(philos, philos[i].time_to_die))
		{
			print_message("died", &philos[i], philos[i].id);
			pthread_mutex_lock(philos[0].dead_lock);
			*philos->dead = 1;
			pthread_mutex_unlock(philos[0].dead_lock);
			return (FAIL);
		}
		i++;
	}
	return (SUCCESS);
}

int	philo_ate(t_philo *philos)
{
	int	i;
	int	done;

	i = 0;
	done = 0;
	if (philos[0].nb_time_to_eat == -1)
		return (SUCCESS);
	while (i < philos[0].nb_philos)
	{
		pthread_mutex_lock(philos[i].meal_lock);
		if (philos[i].meals_eaten >= philos[i].nb_time_to_eat)
			done++;
		pthread_mutex_unlock(philos[i].meal_lock);
		i++;
	}
	if (done == philos[0].nb_philos)
	{
		pthread_mutex_lock(philos[0].dead_lock);
		*philos->dead = 1;
		pthread_mutex_unlock(philos[0].dead_lock);
		return (FAIL);
	}
	return (SUCCESS);
}
