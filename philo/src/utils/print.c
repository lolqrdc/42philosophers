/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolq <lolq@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 17:45:37 by lolq              #+#    #+#             */
/*   Updated: 2025/05/08 17:45:48 by lolq             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void    print_message(char *str, t_philo *philo, int id)
{
    size_t  time;

    pthread_mutex_lock(philo->write_lock);
    time = current_time() - philo->start_time;
    if (!is_philo_dead(philo))
        printf("%zu %d %s\n", time, id, str);
    pthread_mutex_unlock(philo->write_lock);
}
