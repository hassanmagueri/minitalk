#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

volatile sig_atomic_t bit_received = 0;

void sigusr_handler(int signum) {
    // Handler for SIGUSR1
    if (signum == SIGUSR1) {
        bit_received = 1;
    }
}

int main() {
    pid_t pid; // Process ID

    // Set up signal handler for SIGUSR1
    signal(SIGUSR1, sigusr_handler);

    // Create a child process
    pid = fork();
    if (pid == 0) {
        // Child process
        printf("Child process executing...\n");        
        // Wait for a bit
        sleep(5);        
        // Send a SIGUSR1 signal to the parent process
        kill(getppid(), SIGUSR1);        
        printf("Child process exiting...\n");
        exit(0);
    } else {
        // Parent process
        printf("Parent process executing...\n");        
        // Wait for a bit to receive the signal
        sleep(1);        
        // Check if the bit is received
        if (bit_received) {
            printf("Bit received from child process.\n");
        } else {
            printf("No bit received from child process.\n");
        }        printf("Parent process exiting...\n");
        exit(0);
    }    
    return 0;
}
