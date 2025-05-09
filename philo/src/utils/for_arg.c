/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 11:35:08 by lolq              #+#    #+#             */
/*   Updated: 2025/05/09 11:33:34 by loribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/* @brief fonctions utilitaires pour faire fonctionner le programme. */

int	ft_atoi(char *str)
{
	int	res;
	int	sig;
	int	i;

	i = 0;
	sig = 1;
	res = 0;
	if (ft_is_digit(str[i]) != SUCCESS)
		return (-1);
	while ((str[i] == ' ') || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * sig);
}

int	ft_is_digit(int n)
{
	if (n >= '0' && n <= '9')
		return (SUCCESS);
	return (FAIL);
}
