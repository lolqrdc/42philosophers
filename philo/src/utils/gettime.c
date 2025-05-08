/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gettime.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolq <lolq@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 17:31:11 by lolq              #+#    #+#             */
/*   Updated: 2025/05/08 17:33:09 by lolq             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

size_t  current_time(void)
{
    struct timeval  time;
    if (gettimeofday(&time, NULL) == -1)
        printf("gettimeofday() error\n");
    return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int     ft_usleep(size_t milliseconds)
{
    size_t start;

    start = current_time();
    while ((current_time() - start) < milliseconds)
        usleep(500);
    return (0);
}
