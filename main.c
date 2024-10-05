#include "fork.h"


// Process 0 is the main process
int main(int argc, char* argv[]) {
    if(argc < 3) {
        printf("[-] Must pass three arguments: The executable, the number of subprocesses, and the pattern number.\n");
        printf("[-] The number of subprocesses ranges from 1 - 256 and the number of patterns range from 1 - 3.\n");
        printf("[-] EXAMPLE: ./forkythready 145 2\n");
    }

    int process_count = atoi(argv[1]);

    if(atoi(argv[2]) == 1) {
        pattern_1(process_count);

        printf("Process 0 (%d) exiting...\n", getpid());
    } // END - if(atoi(argv[2]) == 1)

    else if(atoi(argv[2]) == 2) {
        pattern_2(0, process_count);

        printf("Process 0 (%d) exiting...\n", getpid());
    } // END - else if(atoi(argv[2]) == 2)
}