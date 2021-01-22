#include <stdio.h>

void move(int N, int from, int to, int middle, int *count)
{
    *count = *count + 1;
    if (N == 1)
    {
        printf("Move disk 1 from %d to %d\n", from, to);
        return;
    }
    move(N - 1, from, middle, to, count);
    printf("Move disk %d from %d to %d\n", N, from, to);
    move(N - 1, middle, to, from, count);
}

int factorial(int N)
{
    if (N == 1)
        return 1;
    return N * factorial(N - 1);
}

int fib(int N, int memo[])
{

    if (N == 1 || N == 2)
    {
        return 1;
    }
    else if (memo[N] == 0)
    {
        memo[N] = fib(N - 1, memo) + fib(N - 2, memo);
    }

    return memo[N];
}

int main()
{
    int count = 0;
    move(3, 0, 2, 1, &count);
    printf("Total count : %d\n", count);
    int ret = factorial(4);
    // const int N = 15;
    // int memo[N+1];

    // unsigned int ret = fib(N, memo);
    // printf("ret : %u\n", ret);
}