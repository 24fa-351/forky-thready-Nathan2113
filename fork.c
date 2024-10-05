#include "fork.h"

void pattern_1(int process_count) {
    srand(time(NULL));

    pid_t *pids = malloc(process_count * sizeof(pid_t)); // Allocate memory for pid's stored

    for(int i = 0; i < process_count; i++) {
        pid_t pid = fork();

        if(pid < 0) { // pid will be < 0 if the fork failed
            printf("Fork failed");
            exit(EXIT_FAILURE);
        } // END - if(pid < 0)

        else if(pid == 0) { // do second process
            printf("Process 0 (%d) creating Process %u (%d)\n", getppid(), i + 1, getpid());

            printf("Process %u beginning\n\n", i + 1);

            exit(0); // End child process
        } // END else if(pid == 0)
        else {
            pids[i] = pid;
        } // END - else

        sleep(0.01); // Sleep for 0.01 seconds to prevent multiple fork outputs at the same time
    } // END - for(int i = 1; i <= process_count; i++)

    for(int i = 0; i < process_count; i++) {
        waitpid(pids[i], NULL, 0); // Waits for each child to finish
        printf("Process %u (%d) exiting...\n", i + 1, pids[i]);

        sleep((rand() % 8) + 1); // Sleep for a random number of seconds (from 1 - 8)
    } // END - for(int i = 0; i < process_count; i++)
}


void pattern_2(int current_process, int process_count) {
    srand(time(NULL));

    if(current_process < process_count) {
        printf("Process %u beginning\n", current_process);

        pid_t pid = fork();

        sleep((rand() % 8) + 1); // Sleep for a random number of seconds (from 1 - 8)

        if(pid < 0) { // pid will be < 0 if the fork failed
            printf("Fork failed");
            exit(EXIT_FAILURE);
        } // END - if(pid < 0)

        else if(pid == 0) {
            printf("Process %u (%d) creating Process %u (%d)\n\n", current_process, getppid(), current_process + 1, getpid());

            pattern_2(current_process + 1, process_count);

            printf("Process %u (%d) exiting...\n", current_process + 1, getpid());

            exit(0); // Exit processes once recursion returns
        } // END - else if(pid == 0)
        
        else { // Wait until the child process is finished before exiting the parent
            wait(NULL);
        } // END - else

    } // END - if(current_process < process_count)

    return;
}
