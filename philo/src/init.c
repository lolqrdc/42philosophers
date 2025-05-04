/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolq <lolq@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 13:49:38 by lolq              #+#    #+#             */
/*   Updated: 2025/05/04 14:55:42 by lolq             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

/* Initialisation des inputs proposé par l'utilisateur. */
void    init_input(t_philo  *philo, char **av)
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

/* Initisalition de la structure philo en entier. */
void    init_philos(t_philo *philos, t_program *program, pthread_mutex_t *fork, char **av)
{
    int i;

    i = 0;
    while (i < ft_atoi(av[1]))
    {
        philos[i].id = i + 1;
        philos[i].eating = 0;
        philos[i].meals_eaten = 0;
        init_input(&philos[i], av);
        philos[i].start_time = current_timing();
        philos[i].last_meal = current_timing();
        philos[i].write_lock = &program->write_lock;
        philos[i].dead_lock = &program->dead_flag;
        philos[i].meal_lock = &program->meal_lock;
        philos[i].dead = &program->dead_flag;
        philos[i].l_fork = &fork[i];
        if (i == 0)
            philos[i].r_fork = &fork[philos[i].nb_philos - 1];
        else
            philos[i].r_fork = &fork[i - 1];
        i++;
    }
}

/* Initialisation des mutex pour les fourchettes. */
void    init_fork(pthread_mutex_t *forks, int nb_philos)
{
    int i;

    i = 0;
    while (i < nb_philos)
    {
        pthread_mutex_init(&forks[i], NULL);
        i++;
    }
}

/* Initialisation des mutex du programme. */
void    init_program(t_program *program, t_philo *philos)
{
    program->dead_flag = 0;
    program->philos = philos;
    pthread_mutex_init(&program->write_lock, NULL);
    pthread_mutex_init(&program->meal_lock, NULL);
    pthread_mutex_init(&program->dead_lock, NULL);

}