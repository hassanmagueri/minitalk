#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    char c = 100;
    int n1 = c>>atoi(argv[1]);
    int n2 = c>>(atoi(argv[1]) + 1);
    printf("%d\n", n1);
    printf("%d\n", n1 % 2);
    // printf("%d\n", n2);
    return 0;
}
//1100100