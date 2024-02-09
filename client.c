#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <limits.h>

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

	if (argc != 3 || atoi(argv[1]) < 0 || atoi(argv[1]) > INT_MAX)
		return 1;
	int	i =0;
	printf("%s", str);
	if(argc == 1)
		return 0;
	int pid = atoi(argv[1]);
	i = 0;
	printf("%d\n", argv[2][0]);
	while (s[i])
		send_byte(pid, s[i++]);
	return 0;
}
