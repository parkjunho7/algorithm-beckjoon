#include <iostream>
#include <stack>
#include <vector>
using namespace std;

const int N = 7;
int visited[N] = {
    0,
};
vector<int> v[N + 1];

void dfs(int start)
{
    if(visited[start] == 1) return;
    printf("%d ", start);
    visited[start] = 1;

    for(int i=0; i<v[start].size(); i++){
        int next = v[start][i];
        if(visited[next] != 1)
            dfs(next);
    }
}
int main()
{
    //link 1 and 2
    v[1].push_back(2);
    v[2].push_back(1);

    //link 1 and 3
    v[1].push_back(3);
    v[3].push_back(1);

    //link 2 and 3
    v[2].push_back(3);
    v[3].push_back(2);

    //link 2 and 4
    v[2].push_back(4);
    v[4].push_back(2);

    //link 2 and 5
    v[2].push_back(5);
    v[5].push_back(2);

    //link 4 and 5
    v[4].push_back(5);
    v[5].push_back(4);

    //link 3 and 6
    v[3].push_back(6);
    v[6].push_back(3);

    //link 3 and 7
    v[3].push_back(7);
    v[7].push_back(3);

    //link 6 and 7
    v[6].push_back(7);
    v[7].push_back(6);

    dfs(1);

    return 0;
}