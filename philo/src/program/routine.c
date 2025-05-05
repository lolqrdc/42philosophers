/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolq <lolq@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 15:10:10 by lolq              #+#    #+#             */
/*   Updated: 2025/05/05 16:48:37 by lolq             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

/* @brief Création de la routine des philosophes, la fonction va s'arrêter dès 
que 'dead_flag' est a 1. */

void    philo_routine(void *arg)
{
    t_philo *philo;
    philo = (t_philo *)arg;
    if (philo->id % 2 == 0)
        ft_usleep(1);
    while (!is_dead(philo))
    {
        eating(philo);
        sleeping(philo);
        thinking(philo);
    }
    return (arg);
}
void    thinking(t_philo *philo)
{
    print_action("is thinking", philo, philo->id);
}

void    sleeping(t_philo *philo)
{
    print_action("is sleeping", philo, philo->id);
    ft_usleep(philo->time_to_sleep);
}

void    eating(t_philo *philo)
{
    if (philo->id % 2 == 0)
    {
        pthread_mutex_lock(philo->r_fork);
        print_action("has taken a fork", philo, philo->id);
        pthread_mutex_lock(philo->l_fork);
        print_action("has taken a fork", philo, philo->id);
    }
    else
    {
        pthread_mutex_lock(philo->l_fork);
        print_action("has taken a fork", philo, philo->id);
        pthread_mutex_lock(philo->r_fork);
        print_action("has taken a fork", philo, philo->id);
    }
    philo->eating = 1;
    print_action("is eating", philo, philo->id);
    pthread_mutex_lock(philo->meal_lock);
    philo->last_meal = current_time();
    philo->meals_eaten++;
    pthread_mutex_unlock(philo->meal_lock);
    ft_usleep(philo->time_to_eat);
    philo->eating = 0;
    pthread_mutex_unlock(philo->l_fork);
    pthread_mutex_unlock(philo->r_fork);
}

int is_dead(t_philo *philo)
{
    int dead;
    pthread_mutex_lock(philo->dead_lock);
    dead = *(philo->dead);
    pthread_mutex_unlock(philo->dead_lock);
    return (dead);
}
