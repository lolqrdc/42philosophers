/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolq <lolq@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 10:31:43 by lolq              #+#    #+#             */
/*   Updated: 2025/05/05 16:40:58 by lolq             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

/* @brief  Création d'autant de threads qu'il y a de philosophes et création
d'un thread supplémentaire, qui est le surveillant (monitor). Ensuite, les 
threads sont join. */

int thread_create(t_program *program, pthread_mutex_t *forks)
{
    pthread_t   monitor;
    int         i;

    i = 0;
    if (pthread_create(&monitor, NULL, monitor_routine, program->philos) != 0)
    {
        write(2, "Thread creation error\n", 23);
        destroy_mutex(program, forks);
        return (FAIL);
    }
    while (i < program->philos[0].nb_philos)
    {
        if (pthread_create(&program->philos[i].thread, NULL, philo_routine, &program->philos[i]) != 0)
        {
            write(2, "Thread creation error\n", 23);
            destroy_mutex(program, forks);
            return (FAIL);
        }        
        i++;
    }
    i = 0;
    if (pthread_join(monitor, NULL) != 0)
    {
        write(2, "Thread join error\n", 19);
        destroy_mutex(program, forks);
        return (FAIL);
    }
    while (i < program->philos[0].nb_philos)
    {
        if (pthread_join(program->philos[i].thread, NULL) != 0)
        {
            write(2, "Thread join error\n", 19);
            destroy_mutex(program, forks);
            return (FAIL);
        }
        i++;
    }
    return (SUCCESS);  
}

void destroy_mutex(t_program *program, pthread_mutex_t *fork)
{
    int i;

    i = 0;    
    while (i < program->philos->nb_philos)
    {
        pthread_mutex_destroy(&fork[i]);
        i++;
    }
    pthread_mutex_destroy(&program->dead_lock);
    pthread_mutex_destroy(&program->meal_lock);
    pthread_mutex_destroy(&program->write_lock);
}
