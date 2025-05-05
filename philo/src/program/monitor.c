/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolq <lolq@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 15:10:27 by lolq              #+#    #+#             */
/*   Updated: 2025/05/05 16:51:31 by lolq             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

/* @brief Le thread monitor est un surveillant, il regarde si un philo est mort 
et si il a assez mangé. */

void    *monitor(void *arg)
{
    t_philo *philo;

    philo = (t_philo *)arg;
    while (1)
    {
        if (check_philo_death(philo) == 1 || philo_ate(philo) == 1)
            break ;
    }
    return (arg);
}

int philo_is_dead(t_philo *philo, size_t time_to_die)
{

}

int check_philo_death(t_philo *philo)
{
    
}

int philo_ate(t_philo *philo)
{
    
}