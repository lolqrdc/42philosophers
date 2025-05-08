/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolq <lolq@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 18:08:13 by lolq              #+#    #+#             */
/*   Updated: 2025/05/08 18:10:46 by lolq             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void    one_philo(t_philo *philo)
{
    printf("0 1 has taken a fork\n");
    ft_usleep(philo->time_to_die);
    printf("%u 1 died\n", philo->time_to_die);
}