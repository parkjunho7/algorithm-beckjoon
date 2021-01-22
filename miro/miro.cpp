#include <iostream>
#include <vector>
#include <queue>

using namespace std;


int N, M;
int pathcount;
bool ptVisited[100][100];
int minPath = 10000;
vector<int> ptMap[100];

void bfs(int row, int col, int step)
{
    step = 1;
    queue<pair<int, int> > q;
    q.push(make_pair(row, col));
    queue<int> stepQ;
    stepQ.push(step);
    int dRow[] = {1, 0, -1, 0};
    int dCol[] = {0, -1, 0, 1};
    while (!q.empty())
    {
        pair<int, int> current = q.front();
        //printf(" visited >> [%d][%d] count add : %d\n", current.first, current.second, stepQ.front());
        q.pop();
        step = stepQ.front();
        stepQ.pop();
        if (current.first == N - 1 && current.second == M - 1)
        {
            //printf(" GOAL!! >> [%d][%d]\n", current.first, current.second);
            if (step < minPath)
            {
                minPath = step;
            }
            return;
        }

        for (int i = 0; i < 4; i++)
        {
            int nextRow = current.first + dRow[i];
            int nextCol = current.second + dCol[i];
            if (nextRow >= 0 && nextRow < N && nextCol >= 0 && nextCol < M)
            {
                if (ptMap[nextRow][nextCol] == 1 && ptVisited[nextRow][nextCol] == false)
                {
                    stepQ.push(step+1);
                    q.push(make_pair(nextRow, nextCol));
                    ptVisited[nextRow][nextCol] = true;
                }
            }
        }
    }
}
void dfs(int row, int col, int pathcount)
{
    //printf("Row : %d, Col : %d\n", row, col);
    if (row < 0 || row > N - 1 || col < 0 || col > M - 1)
        return;
    if (ptVisited[row][col] == true)
    {
        //printf("already visited [%d][%d]\n", row, col);
        return;
    }
    // printf(" check >> [%d][%d]\n", row, col);
    if (row == N - 1 && col == M - 1)
    {
        //printf(" GOAL!! >> [%d][%d]\n", row, col);
        if (pathcount < minPath)
        {
            minPath = pathcount;
        }
        return;
    }

    ptVisited[row][col] = true;

    //printf(" visited >> [%d][%d] count add : %d\n", row, col, pathcount);

    int dRow[] = {1, 0, -1, 0};
    int dCol[] = {0, -1, 0, 1};

    for (int i = 0; i < 4; i++)
    {
        int nextRow = row + dRow[i];
        int nextCol = col + dCol[i];
        if (nextRow >= 0 && nextRow <= N - 1 && nextCol >= 0 && nextCol <= M - 1)
        {

            // printf("NextRow : %d, NextCol : %d\n", nextRow, nextCol);
            if (ptMap[nextRow][nextCol] == 1 && ptVisited[nextRow][nextCol] == false)
            {
                dfs(nextRow, nextCol, pathcount + 1);
                ptVisited[nextRow][nextCol] = false;
            }
        }
    }
}

int main()
{
    scanf("%d %d", &N, &M);
    
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            int temp;
            scanf("%1d", &temp);
            ptMap[i].push_back(temp);
            ptVisited[i][j] = false;
        }
    }

    // dfs(0, 0, 1);
    bfs(0, 0, 1);
    if(minPath == 10000)
        minPath = 0; 
    printf("%d\n", minPath);
}