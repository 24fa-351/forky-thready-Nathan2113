#include "fork.h"

void pattern_1(int process_count) {
    srand(time(NULL));

    int sleep_timer = 0;

    for(int i = 0; i < process_count; i++) {
        pid_t pid = fork();
        sleep_timer = (rand() % 8) + 1;

        if(pid < 0) { // pid will be < 0 if the fork failed
            printf("Fork failed");
            exit(EXIT_FAILURE);
        } // END - if(pid < 0)

        else if(pid == 0) { // do second process
            printf("Process 0 (%d) creating Process %u (%d)\n", getppid(), i + 1, getpid());

            printf("Process %u created: Sleeping for %u seconds...\n", i + 1, sleep_timer);

            sleep(sleep_timer);

            printf("Process %u (%d) exiting...\n\n", i + 1, getpid());
            exit(0); // End child process
        } // END else if(pid == 0)
        else {
            wait(NULL);
        } // END - else

    } // END - for(int i = 1; i <= process_count; i++)

}


void pattern_2(int current_process, int process_count) {
    srand(time(NULL));
    int sleep_timer = 0;
    sleep_timer = (rand() % 8) + 1;

    if(current_process < process_count) {
        printf("Process %u (%d) created: Sleeping for %u seconds...\n\n", current_process, getpid(), sleep_timer);

        pid_t pid = fork();

        sleep(sleep_timer); // Sleep for a random number of seconds (from 1 - 8)

        if(pid < 0) { // pid will be < 0 if the fork failed
            printf("Fork failed");
            exit(EXIT_FAILURE);
        } // END - if(pid < 0)

        else if(pid == 0) {
            printf("Process %u (%d) creating Process %u (%d)\n", current_process, getppid(), current_process + 1, getpid());

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

void pattern_3(int current_process, int process_count) {
    if(current_process >= process_count) {
        return; // No more forks required
    }

    srand(time(NULL));
    int sleep_timer = 0;
    sleep_timer = (rand() % 8) + 1;

    printf("Process %u (%d) created: Sleeping for %u seconds...\n", current_process, getpid(), sleep_timer);
    

    sleep(sleep_timer);

    pid_t pid = fork();

    if(pid < 0) {
        printf("Fork Failed...\n\n");
        exit(EXIT_FAILURE);
    }

    else if(pid == 0) {
        // printf("Process %d creating Process %u (%d)\n", getppid(), current_process + 1, getpid());

        if(current_process != 0 && current_process % 2 == 1) {
            printf("Parent: creating left child %u (%d)\n", current_process + 1, getpid());
        }
        else if(current_process != 0 && current_process % 2 == 0) {
            printf("Parent: creating right child %u (%d)\n", current_process + 1, getpid());
        }

        // Recursively create left child
        pattern_3(2 * current_process + 1, process_count);

        // Recursively create right child
        pattern_3(2 * current_process + 2, process_count);

        printf("Process %u (%d) exiting...\n", current_process + 1, getpid());

        exit(0); // Exit process once recursion returns
    }

    else {
        // Wait for child process to finish
        wait(NULL);
    }

    return;
}