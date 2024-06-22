## 🧾 Subject - Understand

We need to understand the concept of thread in the context of the Philosopher. So, what is a Philosopher?

A Philosopher refers to the process of eating, thinking, sleeping, and dying. Here, thread can be likened to food, and processes like eating can be facilitated with tools like a fork or a spoon.

How does a Philosopher die? A Philosopher may die if they do not eat in time or lack the necessary tools like a spoon to eat with.

And how does a Philosopher sleep? A Philosopher should sleep after eating; if they are full, they should sleep and then repeat the cycle.

## ✨ Key Focus

The project is implemented in C and uses the pthread library for thread management in the Mandatory part and fork for process management in the Bonus part. The project has the following key features:

- Each philosopher is a separate thread/process depending on the part.
- Each philosopher has a fork on the left and a fork on the right.
- A philosopher can only eat if he has both forks.
- A fork can be a Mutex or Semaphore depending on the part.
- Each philosopher has a state: thinking, eating, sleeping, dead.
- Each philosopher has a `time_to_die`, `time_to_eat`, `time_to_sleep`, and `number_of_times_to_eat`.
- The simulation stops when a philosopher dies or when all philosophers have eaten `number_of_times_to_eat` times.

## 📝 Consept - Routine

`While they are eating`, they are not thinking or sleeping;
`While thinking`, they are not eating or sleeping;

First Consept I need to take for and full eating! and next Lock if finish
Eatting `id % 2 == 0` I think this's should good 

```
void	*routine(void *add)
{
	/** Consept:
	 *
	 * Made: function for each philosopher;
	 * 
	 * Take fork;
	 * Eat;
	 * Sleep;
	 * Think;
	 * Lock -> Fork -> Philo_id -> M_Dead;
	 * Repeat;
	 * Unlock -> Fork -> Philo_id -> M_Dead;
	 * 
	 */
	return (NULL);
}
```
