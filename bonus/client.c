#include "../minitalk.h"

int	send_byte( int pid, unsigned char c)
{
	int i = 8;
	while (i--)
	{
		if ((c >> i) % 2)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(500);
	}
	return 0;
}

int main(int argc, char const *argv[])
{
	const char *s = argv[2];
	char str[100];

	if (argc != 3 || ft_atoi(argv[1]) < 0 || ft_atoi(argv[1]) > INT_MAX)
		return 1;
	int	i = 0;
	if(argc == 1)
		return 0;
	int pid = ft_atoi(argv[1]);
	i = 0;
	// printf("%d\n", argv[2][0]);
	// while (ss[i])
		// send_byte(pid, 'a');
		// send_byte(pid, 'a');
		// send_byte(pid, 240);
	while (s[i])
		send_byte(pid, s[i++]);
	send_byte(pid, 0);
	return 0;
}
