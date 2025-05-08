/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolq <lolq@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 11:12:16 by lolq              #+#    #+#             */
/*   Updated: 2025/05/08 22:25:54 by lolq             ###   ########.fr       */
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
# define SUCCESS 0

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
int     main(int argc, char **av);

/* Parsing */
int     valid_arg(char **av);

/* Initialisation */
void    init_input(t_philo *philo, char **av);
void    init_philos(t_philo *philos, t_program *program, pthread_mutex_t *fork, char **av);
int     init_program(t_program *program, t_philo *philos);
int     init_fork(pthread_mutex_t *forks, int nb_philos);

/* Gestion des threads */
int     create_thread(t_program *program, pthread_mutex_t *forks);
void    destroy_mutex(t_program *program, pthread_mutex_t *forks);

/* La routine des philosophers */
void    *p_routine(void *arg);
void    p_eating(t_philo *philo);
void    p_sleeping(t_philo *philo);
void    p_thinking(t_philo *philo);
int     philo_deadflag(t_philo *philo);

/* La routine du spy */
void    *s_routine(void *arg);
int     philo_is_dead(t_philo *philo, size_t time_to_die);
int     check_philo_death(t_philo *philos);
int     philo_ate(t_philo *philos);

/* Les fonctions utilitaires */
int	    ft_atoi(char *str);
int	    ft_is_digit(int n);
size_t  current_time(void);
int     ft_usleep(size_t milliseconds);
void    print_message(char *str, t_philo *philo, int id);

/* Cas particulier */
void    one_philo(t_philo *philo);

// ========= DEBUG ========= //
void debug_philo(const t_philo *philo);
void debug_all_philos(const t_philo *philos, int nb);
void debug_program(const t_program *program);
void debug_forks(pthread_mutex_t *forks, int nb);

#endif