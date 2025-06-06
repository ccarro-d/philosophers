

# include "philo.h"

int	main(int argc, char **argv)
{

	t_rules rules;
	t_philo	*philos;
	int	ret;

	if (argc != 5 && argc != 6)
		return(print_error("Invalid numer of arguments"));
	ret = init_rules(&rules, argv);
	if (ret != 0)
		return (ret);
	philos = malloc(sizeof(t_philo) * rules.philo_num);
	if (!philos)
	{
		free(rules.forks);
		return(print_error("Error > Forks allocation failed"));
	}
	ret = init_philos(philos, &rules);
	if (ret != 0)
		return (ret);
	ret = run_simulation(&rules, philos);
	if (ret != 0)
		return (ret);
	free(rules.forks);
	free(philos);
	return (0);
}

/*
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
*/