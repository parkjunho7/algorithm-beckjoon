#include <iostream>

using namespace std;

long long memo[100];
bool visit[100];

//Fn = Fn-1 + Fn-2
long long fib_dfs(int start){
    if(start <= 2)
        return 1;

    if(visit[start] == true)
        return memo[start];

    visit[start] = true;
    
    memo[start-1] = fib_dfs(start - 1);
    memo[start-2] = fib_dfs(start - 2);
    
    
    return memo[start-1] + memo[start-2];    
}

int main(){
    int N = 0;
    scanf("%d", &N);
    long long ret = fib_dfs(N);
    printf("%lld\n", ret);
}