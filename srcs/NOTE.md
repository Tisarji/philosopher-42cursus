## ✨ Key Focus

The project is implemented in C and uses the pthread library for thread management in the Mandatory part and fork for process management in the Bonus part. The project has the following key features:

- Each philosopher is a separate thread/process depending on the part.
- Each philosopher has a fork on the left and a fork on the right.
- A philosopher can only eat if he has both forks.
- A fork can be a Mutex or Semaphore depending on the part.
- Each philosopher has a state: thinking, eating, sleeping, dead.
- Each philosopher has a `time_to_die`, `time_to_eat`, `time_to_sleep`, and `number_of_times_to_eat`.
- The simulation stops when a philosopher dies or when all philosophers have eaten `number_of_times_to_eat` times.
