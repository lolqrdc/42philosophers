/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolq <lolq@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 11:12:16 by lolq              #+#    #+#             */
/*   Updated: 2025/05/08 11:25:41 by lolq             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

/* Les bibliothèques utiles */
# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>

/* Mes defines */
# define PHILO_MAX 200
# define FAIL 1
# define SUCCES 0

/* Mes structures */
typedef struct s_philo
{
    pthread_t       thread;
    int             id;
    int             eating;
    int             meals_eaten;
    size_t          last_meal;
    size_t          time_to_die;
    size_t          time_to_eat;
    size_t          time_to_sleep;
    size_t          start_time;
    int             nb_philos;
    int             nb_time_to_eat;
    int             *dead;
    pthread_mutex_t *r_fork;
    pthread_mutex_t *l_fork;
    pthread_mutex_t *write_lock;
    pthread_mutex_t *dead_lock;
    pthread_mutex_t *meal_lock;

}   t_philo;

typedef struct s_program
{
    int             dead_flag;
    pthread_mutex_t dead_lock;
    pthread_mutex_t meal_lock;
    pthread_mutex_t write_lock;
    t_philo         *philos;

}  t_program;

/* Exécution du programme */
int main (int argc, char **av);

/* Parsing */

/* Initialisation */

/* Gestion des threads */
/* La routine des philosophers */

/* La routine du monitor */

/* Les fonctions utilitaires */


#endif