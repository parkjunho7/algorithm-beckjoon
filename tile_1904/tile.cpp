#include <iostream>

using namespace std;


long long memo[1000000+1];
int N;

long long fib(int n){
    if(n < 1) return 0;
    if(n == 1) return 1;
    if(n == 2) return 2;

    if(memo[n] != 0) return memo[n];

    memo[n-1] = fib(n-1);
    memo[n-2] = fib(n-2);

    memo[n] = memo[n-1] + memo[n-2];
    return memo[n]%15746;
}

int main(){
    scanf("%d", &N);

    long long retN = fib(N);
    printf("%lld\n", retN);

    

}