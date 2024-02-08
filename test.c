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
    if (pid == 1)
    {
        while (1)
        {
            printf("child\n");
            kill(getppid(), SIGKILL);
            usleep(500000);
        }
    }
    else
    {
        // kill(pid, SIGSTOP);
        // unsigned int t;
        // do
        // {
        //     printf("sleep prcess : ");
        //     scanf("%d", &t);
        //     if (t > 0)
        //     {
        //         kill(pid, SIGCONT);
        //         sleep(t);
        //         kill(pid, SIGSTOP);
        //     }
        // } while (t > 0);
        // kill(pid, SIGKILL);

        while (1)
        {
            // printf("%i\n", getpid());
            printf("parent \n");
            kill(getpid(), SIGSEGV);
            kill(getpid(), SIGSEGV);
            kill(getpid(), SIGSEGV);
            kill(getpid(), SIGSEGV);
            usleep(500000);
        }
        
    }
    
    return 0;
}


