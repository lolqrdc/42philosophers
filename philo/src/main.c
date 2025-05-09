/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 11:03:21 by lolq              #+#    #+#             */
/*   Updated: 2025/05/09 18:36:33 by loribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **av)
{
	t_program		program;
	t_philo			philos[PHILO_MAX];
	pthread_mutex_t	forks[PHILO_MAX];

	if (argc != 5 && argc != 6)
		return (printf("Please provide valid arguments.\n"), FAIL);
	if (valid_arg(av) == FAIL)
		return (FAIL);
	if (init_fork(forks, ft_atoi(av[1])) != SUCCESS)
		return (printf("Error while the initialization of the program"), 1);
	if (init_program(&program, philos) != SUCCESS)
	{
		destroy_mutex(&program, forks);
		return (printf("Error while the Initialization of forks mutexes"), 1);
	}
	init_philos(philos, &program, forks, av);
	if (philos->nb_philos == 1)
		one_philo(philos);
	else
	{
		create_thread(&program, forks);
		destroy_mutex(&program, forks);
	}
	return (SUCCESS);
}
