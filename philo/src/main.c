/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolq <lolq@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 13:34:32 by lolq              #+#    #+#             */
/*   Updated: 2025/05/04 14:06:49 by lolq             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h" 

int main (int argc, char **av) 
{
    t_philo philo[PHILO_MAX];

    if (argc != 5 || argc != 6)
        return (write(2, "please provide enough argument\n", 32), FAIL);
    if (!is_valid_arg(av))
        return (FAIL);
}
