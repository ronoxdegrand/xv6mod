To execute this fork of xv6 for experimentation, ensure that you have qemu installed.
Run the following commands:

1. make [SCHEDULER=(FCFS/PBS/RR)]
2. make qemu-nox [SCHEDULER=(FCFS/PBS/RR)] //i prefer this over make qemu because it then begins qemu within the current terminal.

if
    make
    make qemu-nox
is entered, the round robin scheduler will be chosen
    make SCHEDULER=FCFS
    make qemu-nox SCHEDULER=FCFS
is entered, the first come first serve scheduler will be chosen
    make SCHEDULER=PBS
    make qemu-nox SCHEDULER=PBS
is entered, the priority based scheduler will be chosen //logically, i feel my scheduling algorithm for PBS is sound, but because of some minor bug, i cannot get it to work. xv6 bugs out and takes no commands, and then you'll have to quit

To quit this fork of xv6, press 'CTRL + A, X'

List of changes in this fork:

1. waitx (system call)
    it takes 2 integer pointers as arguements, which it updates as the total wait time and total run time of a process's children.
    it returns the pid of the current process when successful, else it returns -1.
2. time (user program)
    it takes 1 CLI arguement, the user program that you wish to time. It returns wait time and run time.
3. test1 (user program)
    it is a test for the time user program taking no arguements and making no output.

4. ps (user program)
    it takes in no arguements. It's output is a list of processes' pid, state, name, priority, run time, and wait time in that order.

5. FCFS (scheduler)
    It is a first come first serve scheduler.

6. PBS (scheduler)
    It is a priority based scheduler. Because of minor bugs, the system doesnt function with this scheduler.
7. set_priority (system call)
    It can change the priority of a process. Because of a minor bug, this system call doesnt seem to function. It is called in init.c to change the priority of that to 1, which functions perfectly. But for some reason, using the setPriority command below, I cannot change any other priorities. Due to a lack of time I must terminate further debugging.
8. setPriority (user program)
    It takes in 2 inputs, first being the new priority, second being the pid of the process to have its priority changed. This program in itself functions very well due to its nature. But since the system call that it utilises is buggy, I cannot comment further.