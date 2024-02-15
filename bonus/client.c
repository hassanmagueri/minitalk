#include "../minitalk.h"

int send_byte(int pid, unsigned char c)
{
	int i = 8;
	while (i--)
	{
		if ((c >> i) % 2)
			my_kill(pid, 1);
		else
			my_kill(pid, SIGUSR2);
		usleep(100);
		usleep(100);
	}
	return 0;
}

int is_funct(const char *s, int (*f)(int c))
{
	int i;

	i = 0;
	while (s[i])
	{
		if (f(s[i]) == 0)
			print_error_exit("invalid PID");
		i++;
	}
	return (1);
}

void siguser(int sig)
{
	ft_putendl_fd("message send with success", 1);
}

int main(int argc, char const *argv[])
{
	const char *s = argv[2];
	struct sigaction sa;
	int pid;
	int i = 0;

	i = 0;
	if (argc != 3)
		print_error_exit("more or less args that we want");
	is_funct(argv[1], ft_isdigit);
	pid = ft_atoi(argv[1]);
	if(pid <= 0 || pid > INT_MAX)
		print_error_exit("invalid PID");
	sa.sa_flags = 0;
	sa.sa_handler = siguser;
	sigaction(SIGUSR1, &sa, NULL);
	while (s[i])
		send_byte(pid, s[i++]);
	send_byte(pid, '\0');
	return (0);
}
