/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolq <lolq@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 14:22:52 by lolq              #+#    #+#             */
/*   Updated: 2025/05/08 18:18:41 by lolq             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/* @brief : Init les inputs proposé par l'utilisateur, init les values d'un
philo, init du programme en entier et init les fourchettes. */

void    init_input(t_philo *philo, char **av)
{
    philo->nb_philos = ft_atoi(av[1]);
    philo->time_to_die = ft_atoi(av[2]);
    philo->time_to_eat = ft_atoi(av[3]);
    philo->time_to_sleep = ft_atoi(av[4]);
    if (av[5])
        philo->nb_time_to_eat = ft_atoi(av[5]);
    else
        philo->nb_time_to_eat = -1;
}

void    init_philos(t_philo *philo, t_program *program, pthread_mutex_t *fork, char **av)
{
    int i;

    i = 0;
    while (i < ft_atoi(av[1]))
    {
        philo[i].id = i + 1;
        philo[i].eating = 0;
        philo[i].meals_eaten = 0;
        init_input(&philo[i], av);
        philo[i].start_time = current_time();
        philo[i].last_meal = current_time();
        philo[i].write_lock = &program->write_lock;
        philo[i].dead_lock = &program->dead_lock;
        philo[i].meal_lock = &program->meal_lock;
        philo[i].dead = &program->dead_flag;
        philo[i].l_fork = &fork[i];
        if (i == 0)
            philo[i].r_fork = &fork[philo[i].nb_philos - 1];
        else
            philo[i].r_fork = &fork[i - 1];
        i++;
    }
}

int init_program(t_program *program, t_philo *philos)
{
    program->dead_flag = 0;
    program->philos = philos;
    if (pthread_mutex_init(&program->write_lock, NULL) != 0)
        return (FAIL);
    if (pthread_mutex_init(&program->meal_lock, NULL) != 0)
        return (FAIL);
    if (pthread_mutex_init(&program->dead_lock, NULL) != 0)
        return (FAIL);
    return (SUCCESS);
}

int    init_fork(pthread_mutex_t *forks, int nb_philos)
{
    int i;

    i = 0;
    while (i < nb_philos)
    {
        if (pthread_mutex_init(&forks[i], NULL) != 0)
            return (FAIL);
        i++;
    }
    return (SUCCESS);
}
