/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolq <lolq@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 16:49:05 by lolq              #+#    #+#             */
/*   Updated: 2025/05/08 18:07:44 by lolq             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/* @brief La routine à suivre pour chaque philosophe, et va vérifier si un
philosophe est mort. */

void p_routine(void *arg)
{
    t_philo *philo;
    
    philo = (t_philo *)arg;
    if (philo->id % 2 == 0)
        ft_usleep(1);
    while (!is_philo_dead(philo))
    {
        p_eating(philo);
        p_sleeping(philo);
        p_thinking(philo);
    }
    return (arg);
}

void    p_eating(t_philo *philo)
{
    if (philo->id % 2 == 0)
    {
        pthread_mutex_lock(philo->r_fork);
        print_message("has taken a fork", philo, philo->id);
        pthread_mutex_lock(philo->l_fork);
        print_message("has taken a fork", philo, philo->id);
    }
    else
    {
        pthread_mutex_lock(philo->l_fork);
        print_message("has taken a fork", philo, philo->id);
        pthread_mutex_lock(philo->r_fork);
        print_message("has taken a fork", philo, philo->id);
    }
    philo->eating = 1;
    print_message("is eating", philo, philo->id);
    pthread_mutex_lock(philo->meal_lock);
    philo->last_meal = current_time();
    philo->meals_eaten++;
    pthread_mutex_unlock(philo->meal_lock);
    ft_usleep(philo->time_to_eat);
    philo->eating = 0;
    pthread_mutex_unlock(philo->l_fork);
    pthread_mutex_unlock(philo->r_fork);
}

void    p_sleeping(t_philo *philo)
{
    print_message("is sleeping", philo, philo->id);
    ft_usleep(philo->time_to_sleep);
}

void    p_thinking(t_philo *philo)
{
    print_message("is thinking", philo, philo->id);
}

int is_philo_dead(t_philo *philo)
{
    int dead;

    pthread_mutex_lock(philo->dead_lock);
    dead = *(philo->dead);
    pthread_mutex_unlock(philo->dead_lock);
    return (dead);
}
