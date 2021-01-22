#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define MAXNODE 1000+1
#define MAXEDGE 10000+1

vector<int> *ptVec;
bool visited[MAXNODE];
bool visitedbfs[MAXNODE];
int start;

void dfs(int start)
{
    if (visited[start] == true)
        return;
    visited[start] = 1;
    printf("%d ", start);
    for (int i = 0; i < ptVec[start].size(); i++)
    {
        int next = ptVec[start][i];
        if (visited[next] == false)
        {
            dfs(next);
        }
    }
}
void bfs(int start)
{
    queue<int> q;
    q.push(start);
    visitedbfs[start] = true;
    printf("%d ", start);
    while (!q.empty())
    {
        int current = q.front();
        q.pop();
        for (int i = 0; i < ptVec[current].size(); i++)
        {
            int next = ptVec[current][i];
            if (visitedbfs[next] == false)
            {
                q.push(next);
                visitedbfs[next] = true;
                printf("%d ", next);
            }
        }
    }
}

int main()
{

    int n, e;
    scanf("%d %d %d", &n, &e, &start);
    vector<int> v[n + 1];
    ptVec = v;

    for (int i = 0; i < e; i++)
    {
        int e1, e2;
        scanf("%d %d", &e1, &e2);
        v[e2].push_back(e1);
        v[e1].push_back(e2);
    }

    // printf("--------------------------\n");
    for (int i = 1; i <= n; i++)
    {
        sort(v[i].begin(), v[i].end());
    }

    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 0; j < v[i].size(); j++)
    //     {
    //         printf("%d ", v[i][j]);
    //     }
    //     printf("\n");
    // }
    // printf("--------------------------\n");

    dfs(start);
    printf("\n");
    bfs(start);
}