#include "../minitalk.h"

void reset_buffer(unsigned char buffer[], int *buffer_index, int *bits_index)
{
	buffer[0] = 0;
	buffer[1] = 0;
	buffer[2] = 0;
	buffer[3] = 0;
	buffer[4] = 0;
	(*buffer_index) = 0;
	(*bits_index) = 0;
}

void print_buffer(unsigned char buffer[], int buffer_index)
{
	int i = 0;
	while (i <= buffer_index)
		write(1, &buffer[i++], 1);
}

void	handling_buffer(unsigned char buffer[], int *buffer_index, pid_t si_pid)
{
	if (buffer[(*buffer_index)] == '\0')
	{
		print_buffer(buffer, (*buffer_index));
		my_kill(si_pid, SIGUSR1);
	}
	else if (buffer[0] == 240)
	{
		(*buffer_index)++;
		if ((*buffer_index) == 4)
		{
			print_buffer(buffer, (*buffer_index));
			reset_buffer(buffer, buffer_index, buffer_index);
		}
	}
	else
	{
		write(1, &buffer[0], 1);
		buffer[(*buffer_index)] = 0;
	}
}

void siguser(int n, siginfo_t *sig_info, void *unused)
{
	static unsigned char	buffer[5];
	static int				bits_index;
	static int				current_pid;
	static int				buffer_index;

	if (current_pid == 0)
		current_pid = sig_info->si_pid;
	else if (current_pid != sig_info->si_pid)
	{
		reset_buffer(buffer, &buffer_index, &bits_index);
		current_pid = sig_info->si_pid;
	}
	buffer[buffer_index] = buffer[buffer_index] * 2 + (SIGUSR1 == n);
	bits_index++;
	if (bits_index == 8)
	{
		handling_buffer(buffer, &buffer_index, sig_info->si_pid);
		bits_index = 0;
	}
	(void)unused;
}

int main(int ac, char *av[])
{
	struct sigaction sa;

	if(ac != 1)
		return 1;

	ft_putstr_fd("pid ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putendl_fd("",1);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = siguser;
	sigaction(SIGUSR1,&sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while(1)
		pause();
	return 0;
}
