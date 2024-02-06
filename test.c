#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

// void    hundler(int num)
// {
//     puts("I want die");
// }

int main(int argc, char const *argv[])
{
    // signal(SIGINT, hundler);
    // while (1)
    // {
    //     printf("Wasting your cycles. %d\n", getpid());
    //     sleep(1);
    // }
    


    int pid = fork();
    if (pid == -1)
        return 1;
    if (pid == 0)
    {
        while (1)
        {
            printf("just a test %i\n", getpid());
            usleep(500000);
        }
    }
    else
    {
        printf("ma3art %i\n", getpid());
        sleep(2);
        kill(pid, SIGKILL);
    }
    
    return 0;
}


