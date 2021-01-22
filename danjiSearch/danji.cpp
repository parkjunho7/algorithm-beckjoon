#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

#define MAXSIZE 26
int N;

bool visited[MAXSIZE][MAXSIZE];
vector<char> map[MAXSIZE];
int houseCnt = 0;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
vector<int> vec;

void bfs(int row, int col)
{
    queue<pair <int, int> > q;
    q.push(make_pair(row, col));
    visited[row][col] = 1;
    houseCnt++;
    while (!q.empty())
    {
        pair<int, int> top = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nextRow = top.first + dx[i];
            int nextCol = top.second + dy[i];
            if (nextRow >= 0 && nextRow < N && nextCol >= 0 && nextCol < N)
            {
                if (map[nextRow][nextCol] == 1 && visited[nextRow][nextCol] == 0)
                {   
                    //printf("enqueue > [%d][%d]\n", nextRow, nextCol);
                    q.push(make_pair(nextRow, nextCol));
                    visited[nextRow][nextCol] = 1;
                    houseCnt++;
                }
            }
        }
    }
}


void dfs(int row, int col)
{
    visited[row][col] = 1; //방문처리
    houseCnt += 1;

    for (int i = 0; i < 4; i++)
    {
        int nextRow = row + dx[i];
        int nextCol = col + dy[i];
        if (nextRow >= 0 && nextRow < N && nextCol >= 0 && nextCol < N)
        {
            //printf("nextRow : %d , nextCol : %d \n", nextRow, nextCol);
            if (map[nextRow][nextCol] == 1 && visited[nextRow][nextCol] == 0)
            {
                dfs(nextRow, nextCol);
            }
        }
    }
}

int main()
{

    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int input;
            scanf("%1d", &input);
            map[i].push_back(input);
        }
    }

    vector<char> group;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (map[i][j] == 1 && visited[i][j] == 0)
            {
                houseCnt = 0;
                //dfs(i, j);
                bfs(i, j);
                vec.push_back(houseCnt);
            }
        }
    }
    sort(vec.begin(), vec.end());
    cout << vec.size() << endl;

    for (int i = 0; i < vec.size(); i++)
        cout << vec[i] << endl;
}
