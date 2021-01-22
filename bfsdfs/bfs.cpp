#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N = 7;
vector<int> v[8];
queue<int> q;
int visited[8];

void bfs(int index)
{
    q.push(index);
    visited[index] = 1;
    
    while (!q.empty())
    {
        int current = q.front();
        q.pop();
        printf("%d ", current);
        for (int i = 0; i < v[current].size(); i++)
        {
            int next = v[current][i];
            if (!visited[next])
            {
                q.push(next);
                visited[next] = 1;
            }
        }
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

    bfs(1);

    return 0;
}