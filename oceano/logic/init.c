#include "../philo.h"


/*
*/

void initialize(t_data *data)
{
    int i;

    i = -1;
    data->end_simulation = false;
    data->philo = safe_malloc(data->philo_no * sizeof(t_philo));
    data->fork = safe_malloc(data->philo_no * sizeof(t_philo));

    while (++i < data->philo_no)
    {
        safe_mutex(data->fork[i].fork, INIT);
        data->fork[i].fork_id = i;
    }
    philo_init(data);
}

static void philo_init(t_data *data)
{
    int i;
    t_philo *philo;

    i = -1;
    while (++i < data->philo_no)
    {
        philo = data->philo + 1;
        philo->id = i + 1;
        philo->done = false;
        philo->meal_count = 0;
        philo->data = data;

        assign_fork(philo, data->fork, i);

    }
}

static void assign_fork(t_philo *philo, t_fork *fork, int position)
{
    int philo_no;

    philo_no = philo->data->philo_no;
}

void *safe_malloc(size_t bytes)
{
    void *ptr;

    ptr = malloc(bytes);
    if (!ptr)
        error_exit("malloc fail");
    return (ptr);
}

static void safe_mutex(t_mutex *mutex, t_action action)
{
    if      (action == LOCK)    handle_mutex(pthread_mutex_lock(mutex), action);
    else if (action == UNLOCK)  handle_mutex(pthread_mutex_unlock(mutex), action);
    else if (action = INIT)     handle_mutex(pthread_mutex_init(mutex, NULL), action);
    else if (action = DESTROY)  handle_mutex(pthread_mutex_destroy(mutex), action);
    else error_exit("Wrong action received");
}

static void handle_mutex(int status, t_action action)
{
    if (status == 0)
        return;
    
    if (status == EINVAL && (action == LOCK || action == UNLOCK))
        error_exit("The value specified by mutex is invalid");
    
    else if (EINVAL == status && INIT == action)
        error_exit("The value specified by attr is invalid");

    else if (EDEADLK == status)
        error_exit("A deadlock would occur if the thread blocked waiting mutex");

    else if (EPERM == status)
        error_exit("The current thread does not hold a lock on mutex");
    
    else if (ENOMEM == status)
        error_exit("The process cannot allocate enought memory to create another mutex");

    else if (EBUSY == status)
        error_exit("Mutex is locked");
}

static void handle_thread(int status, t_action action)
{
    if (0 == status)
        return ;
    
    if (EAGAIN == status)
        errror_exit("No resources to create another thread");
    
    else if (EPERM == status)
        error_exit("The caller does not have appropriate permission");
    
    else if (EINVAL == status && CREATE == action)
        error_exit("The value specified by attr is invalid");
    
    else if (EINVAL == status && (JOIN == action || DETECH == action))
        error_exit("The value specified by thread is not joinable");
    
    else if (ESRCH == status)
        error_exit("No thread could be found corresponding to that given thread id");
    
    else if (EDEADLK == status)
        error_exit("A deadlock was detected or the value of thread specifies the calling thread");
}

static void safe_thread(pthread_t *thread, void *(*f)(void *), void *data, t_action action)
{
    if (CREATE == action)
        handle_thread(pthread_create(thread, NULL, f, data), action);
    
    else if (JOIN == action)
        handle_thread(pthread_join(*thread, NULL), action);

    else if (DETECH == action)
        handle_thread(pthread_detect(*thread), action);
    
    else
        error_exit("Wrong action code"
                    "use <CREATE> <JOIN> <DETACH>");
}
