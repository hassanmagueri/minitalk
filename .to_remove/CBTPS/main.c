#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

void handler(int sig, siginfo_t *sig_info, void *unused)
{
    if (sig == SIGUSR1)
        printf("\n5 + 5 + 5\n");
}

int main(int argc, char const *argv[])
{
    int pid = fork();
    if (pid == 0)
    {
        sleep(5);
        kill(getppid(), SIGUSR1);
    }
    else
    {
        int x;
        struct sigaction sa;

        sa.sa_flags = SA_RESTART;
        sa.sa_sigaction = handler;
        sigaction(SIGUSR1, &sa, NULL);
        printf("3 x 5: ");
        scanf("%d", &x);
        if (x == 15)
        {
            printf("Right!\n");
            return 1;
        }
        else
            printf("Wrong!\n");
        // while (1)
        //     pause();
    }
    return 0;
}
