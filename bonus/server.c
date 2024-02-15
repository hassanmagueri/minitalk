#include "../minitalk.h"

int bits_count = 0;
int byte = 0;

void siguser(int n, siginfo_t *sig_info, void *unused)
{
	static unsigned char	byte[5];
	static int				bits_index;
	static int				current_pid;
	static int				buffer_index;
	if (current_pid == 0)
		current_pid = sig_info->si_pid;
	else if (current_pid != sig_info->si_pid)
	{
		byte[0] = 0;
		byte[1] = 0;
		byte[2] = 0;
		byte[3] = 0;
		byte[4] = 0;
		bits_index = 0;
		buffer_index = 0;
		current_pid = sig_info->si_pid;
	}
	byte[buffer_index] = byte[buffer_index] * 2 + (SIGUSR1 == n);
	bits_index++;
	if (bits_index == 8)
	{
		if (byte[buffer_index] == '\0')
		{
			if (buffer_index != 0)
			{
				int i = 0;
				while (i <= buffer_index)
					write(1, &byte[i++], 1);
			}
			my_kill(sig_info->si_pid, SIGUSR1);
		}
		else if (byte[0] == 240)
		{
			buffer_index++;
			if (buffer_index == 4)
			{
				byte[4] = 0;
				int i = 0;
				while (i < 4)
					write(1, &byte[i++], 1);
				byte[0] = 0;
				byte[1] = 0;
				byte[2] = 0;
				byte[3] = 0;
				byte[4] = 0;
				buffer_index = 0;
			}
		}
		else
		{
			write(1, &byte[0], 1);
			byte[buffer_index] = 0;
		}
		bits_index = 0;
	}
	(void)unused;
}

int main(int ac, char *av[])
{
	if(ac != 1)
		return 1;

	ft_putstr_fd("pid ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putendl_fd("",1);
	struct sigaction sa;
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = siguser;
	sigaction(SIGUSR1,&sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while(1)
		pause();
	return 0;
}
