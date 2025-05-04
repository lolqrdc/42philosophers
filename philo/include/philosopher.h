/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolq <lolq@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 13:34:38 by lolq              #+#    #+#             */
/*   Updated: 2025/05/04 15:04:48 by lolq             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>

# define PHILO_MAX 200
# define FAIL 1
# define SUCCESS 0

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

/* Execution */
int     main (int argc, char **av);

/* Parsing */
int     is_valid_arg(char **av);

/* Initialisation */
void    init_input(t_philo  *philo, char **av);
void    init_philos(t_philo *philos, t_program *program, pthread_mutex_t *fork, char **av);
void    init_fork(pthread_mutex_t *forks, int nb_philos);
void    init_program(t_program *program, t_philo *philos);


/* Fonctions utiles */
int     ft_atoi(char *str);
size_t  current_time(void);

#endif