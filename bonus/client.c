#include "../minitalk.h"

void print_error_exit()
{
	ft_putendl_fd("error", 2);
	exit(1);
}

int send_byte(int pid, unsigned char c)
{
	int i = 8;
	while (i--)
	{
		if ((c >> i) % 2)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
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
			print_error_exit();
		i++;
	}
	return (1);
}

void siguser(int sig)
{
	write(1, "DONE\n", 5);
}

int main(int argc, char const *argv[])
{
	const char *s = argv[2];
	struct sigaction sa;

	is_funct(argv[1], ft_isdigit);
	if (argc != 3 || ft_atoi(argv[1]) <= 0 || ft_atoi(argv[1]) > INT_MAX)
		return 1;
	sa.sa_flags = 0;
	sa.sa_handler = siguser;
	sigaction(SIGUSR1, &sa, NULL);
	signal(SIGUSR1, siguser);
	int i = 0;
	int pid = ft_atoi(argv[1]);
	i = 0;
	while (s[i])
		send_byte(pid, s[i++]);
	send_byte(pid, '\0');
	pause();
	return (0);
}
