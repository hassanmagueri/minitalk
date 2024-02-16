#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>

int bits_count = 0;
int byte = 0;

void siguser(int n, siginfo_t *sig_info, void *unused)
{
	static unsigned char	byte;
	static int				bits_index;
	static int				current_pid;
	if (current_pid == 0)
		current_pid = sig_info->si_pid;
	else if (current_pid != sig_info->si_pid)
	{
		byte = 0;
		bits_index = 0;
		current_pid = sig_info->si_pid;
	}
	byte = byte * 2 + (SIGUSR1 == n);
	bits_index++;
	if (bits_index == 8)
	{
		write(1, &byte, 1);
		byte = 0;
		bits_index = 0;
	}
	(void)unused;
}

int main(int argc, char const *argv[])
{
	printf("pid %d\n", getpid());
	struct sigaction sa;
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = siguser;
	sigaction(SIGUSR1,&sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while(1)
		pause();
	return 0;
}
//01100011
//01100010
