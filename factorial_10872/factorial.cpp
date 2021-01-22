#include <iostream>

using namespace std;

#define MAXNUM 12;

bool visit[12+1];

int dfs(int start){
    if(start == 1 || start == 0) return 1;
    visit[start] = true;
    int next = start -1;
    if(next > 0 && next < 13 && visit[next] == false){
        return start * dfs(next);
    }
    return -1;
}

int main()
{
    int N;
    scanf("%d", &N);

    int ret = dfs(N);
    printf("%d\n", ret);
}