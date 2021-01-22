#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

//가로, 세로, 배추개수
int M, N, K;

int map[50][50];
int visit[50][50];

int bfs(pair<int, int> cabbages[], int cabbageCnt)
{
    int warmCnt = 0;
    queue<pair<int, int> > q;

    //q.push(make_pair(0, 0));    //start from 0,0

    int nextRow[] = {1, 0, -1, 0};
    int nextCol[] = {0, 1, 0, -1};
    for (int i = 0; i < cabbageCnt; i++)
    {
        if (visit[cabbages[i].first][cabbages[i].second] == 0)
        {
            //printf("push cabbages [%d][%d]\n", cabbages[i].first, cabbages[i].second);
            q.push(cabbages[i]);
            visit[cabbages[i].first][cabbages[i].second] = 1;
            warmCnt++;
        }
        while (!q.empty())
        {

            pair<int, int> current = q.front();
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                pair<int, int> next = make_pair(current.first + nextRow[i], current.second + nextCol[i]);
                if (next.first > -1 && next.first < N && next.second > -1 && next.second < M)
                {
                    if (map[next.first][next.second] == 1 && visit[next.first][next.second] == 0)
                    {
                        q.push(next);
                        visit[next.first][next.second] = 1;
                    }
                }
            }
        }
    }
    return warmCnt;
}

int main()
{
    int testCaseCnt;
    scanf("%d", &testCaseCnt);

    for (int i = 0; i < testCaseCnt; i++)
    {
        scanf("%d %d %d", &M, &N, &K);
        memset(map, 0x00, sizeof(int) * 50 * 50);
        memset(visit, 0x00, sizeof(int) * 50 * 50);
        pair<int, int> cabbages[K];
        for (int j = 0; j < K; j++)
        {
            int row, col;
            scanf("%d %d", &col, &row);
            map[row][col] = 1;
            cabbages[j] = make_pair(row, col); //row, col
        }
        int ret = bfs(cabbages, K);
        printf("%d\n", ret);
        // printf("\n");
        // for(int i=0; i<N; i++){
        //     for(int j=0; j<M; j++){
        //         printf("%d ", map[i][j]);
        //     }
        //     printf("\n");
        // }
    }
}