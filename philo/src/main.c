/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolq <lolq@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 13:34:32 by lolq              #+#    #+#             */
/*   Updated: 2025/05/05 16:34:10 by lolq             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h" 

int main (int argc, char **av) 
{
    pthread_mutex_t forks[PHILO_MAX];
    t_philo         philos[PHILO_MAX];
    t_program       program;

    if (argc != 5 || argc != 6)
        return (write(2, "please provide enough argument\n", 32), FAIL);
    if (!is_valid_arg(av))
        return (FAIL);
    init_program(&program, philos);
    init_fork(forks, ft_atoi(av[1]));
    init_philos(philos, &program, fork, av);
    thread_create(&program, forks);
    destroy_mutex(&program, fork);
    return (SUCCESS);
}
