/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolq <lolq@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 11:03:21 by lolq              #+#    #+#             */
/*   Updated: 2025/05/08 16:07:24 by lolq             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int main (int argc, char **av)
{
    t_program       program;
    t_philo         philos[PHILO_MAX];
    pthread_mutex_t forks[PHILO_MAX];

    if (argc != 5 && argc != 6)
        return (printf("Please provide enough arguments.\n"), FAIL);
    if (valid_arg(av) != SUCCESS)
        return (FAIL);
    init_program(&program, philos);
    init_fork(forks, ft_atoi(av[1]));
    init_philos(philos, &program, fork, av);
    return (SUCCESS);
}

