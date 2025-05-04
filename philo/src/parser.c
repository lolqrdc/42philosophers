/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolq <lolq@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 17:11:32 by lolq              #+#    #+#             */
/*   Updated: 2025/05/02 13:30:55 by lolq             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int is_valid_arg(char **av)
{
    if (ft_atoi(av[1]) > PHILO_MAX || ft_atoi(av[1]) <= 0)
        return (write(2, "invalid numbers of philosophers.\n", 34), FAIL);
    else if (ft_atoi(av[2]) <= 0)
        return (write(2, "invalid time to die.\n", 22), FAIL);
    else if (ft_atoi(av[3]) <= 0)
        return (write(2, "invalid time to eat.\n", 22), FAIL);
    else if (ft_atoi(av[4]) <= 0)
        return (write(2, "invalid time to die.\n", 22), FAIL);
    else if (av[5] && ft_atoi(av[5]) < 0)
        return (write(2, "invalid number of time each philosopher must eat.\n", 51), FAIL);
    return (SUCCESS);
}
