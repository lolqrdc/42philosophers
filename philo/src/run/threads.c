/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolq <lolq@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 16:05:00 by lolq              #+#    #+#             */
/*   Updated: 2025/05/08 17:54:33 by lolq             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/* @brief Création d'autant de threads qu'il y a de philosophes, création
d'un thread supplémentaire, le spy, qui va surveiller. 
Fonction pour join les threads et les détruire si une erreur survient . */

int     create_thread(t_program *program, pthread_mutex_t *forks)
{
    pthread_t   spy;
    int         i;

    i = 0;
    if (pthread_create(&spy, NULL, spy_routine, program->philos) != 0)
        return (destroy_mutex(program, forks), FAIL);
    while (i < program->philos[0].nb_philos)
    {
        if (pthread_create(&program->philos[i].thread, NULL, p_routine, &program->philos[i]) != 0)
            return(destroy_mutex(program, forks), FAIL);
        i++;
    }
    if (pthread_join(spy, NULL) != 0)
        return (destroy_mutex(program, forks), FAIL);
    while (i < program->philos[0].nb_philos)
    {
        if (pthread_join(program->philos[i].thread, NULL) != 0)
            return (destroy_mutex(program, forks), FAIL);
        i++;
    }
    return (SUCCESS);
}

void    destroy_mutex(t_program *program, pthread_mutex_t *forks)
{
    int i;

    i = 0;
    while (i < program->philos->nb_philos)
    {
        pthread_mutex_destroy(&forks[i]);
        i++;
    }
    pthread_mutex_destroy(&program->dead_lock);
    pthread_mutex_destroy(&program->meal_lock);
    pthread_mutex_destroy(&program->write_lock);
}
