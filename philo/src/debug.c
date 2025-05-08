#include "philosophers.h"

void debug_philo(const t_philo *philo)
{
    printf("Philosophe ID: %d\n", philo->id);
    printf("  nb_philos: %d\n", philo->nb_philos);
    printf("  time_to_die: %zu\n", philo->time_to_die);
    printf("  time_to_eat: %zu\n", philo->time_to_eat);
    printf("  time_to_sleep: %zu\n", philo->time_to_sleep);
    printf("  nb_time_to_eat: %d\n", philo->nb_time_to_eat);
    printf("  eating: %d\n", philo->eating);
    printf("  meals_eaten: %d\n", philo->meals_eaten);
    printf("  write_lock: %p\n", (void*)philo->write_lock);
    printf("  dead_lock: %p\n", (void*)philo->dead_lock);
    printf("  meal_lock: %p\n", (void*)philo->meal_lock);
    printf("  dead: %p\n", (void*)philo->dead);
    printf("  l_fork: %p\n", (void*)philo->l_fork);
    printf("  r_fork: %p\n", (void*)philo->r_fork);
    printf("-----------------------\n");
}

void debug_all_philos(const t_philo *philos, int nb)
{
    for (int i = 0; i < nb; i++)
        debug_philo(&philos[i]);
}

void debug_program(const t_program *program)
{
    printf("PROGRAM DEBUG:\n");
    printf("  dead_flag: %d\n", program->dead_flag);
    printf("  philos: %p\n", (void*)program->philos);
    printf("  write_lock: %p\n", (void*)&program->write_lock);
    printf("  meal_lock: %p\n", (void*)&program->meal_lock);
    printf("  dead_lock: %p\n", (void*)&program->dead_lock);
    printf("-----------------------\n");
}

void debug_forks(pthread_mutex_t *forks, int nb)
{
    for (int i = 0; i < nb; i++)
        printf("Fork %d address: %p\n", i, (void*)&forks[i]);
    printf("-----------------------\n");
}