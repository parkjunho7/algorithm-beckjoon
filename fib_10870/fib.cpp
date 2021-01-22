#include <iostream>

using namespace std;

class FIB
{

public:
    long long pmemo[21];
    bool visit[21];
    FIB(int cnt)
    {
        for (int i = 0; i < 21; i++)
        {
            pmemo[i] = 0;
            visit[i] = false;
        }
    }
    long long fib(int start)
    {
        if (start == 0)
            return 0;
        if (start == 1)
            return 1;
        if (visit[start] == true)
            return pmemo[start];

        visit[start] = true;
        pmemo[start - 1] = fib(start - 1);
        pmemo[start - 2] = fib(start - 2);

        return pmemo[start - 1] + pmemo[start - 2];
    }
    void printFib(int n)
    {
        long long ret = fib(n);
        printf("%lld\n", ret);
    }
};

int main()
{
    int n;
    scanf("%d", &n);
    FIB insFib(n);
    insFib.printFib(n);
}