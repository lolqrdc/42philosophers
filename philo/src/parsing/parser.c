/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolq <lolq@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 11:35:23 by lolq              #+#    #+#             */
/*   Updated: 2025/05/08 16:08:01 by lolq             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/*@brief vérification des arguments proposé par l'utilisateur. */

int valid_arg(char **av)
{
    int n;

    n = ft_atoi(av[1]);
    if (n > PHILO_MAX || n <= 0)
        return (printf("invalid numbers of philosophers\n"), FAIL);
    n = ft_atoi(av[2]);
    if (n <= 0)
        return (printf("invalid time to die\n"), FAIL);
    n = ft_atoi(av[3]);
    if (n <= 0)
        return (printf("invalid time to eat\n"), FAIL);
    n = ft_atoi(av[4]);
    if (n <= 0)
        return (printf("invalid time to sleep\n"), FAIL);
    if (av[5])
    {
        n = ft_atoi(av[5]);
        if (n < 0)
            return (printf("invalid number of time each philosopher must eat\n"), FAIL);
    }
    return (SUCCESS);
}
