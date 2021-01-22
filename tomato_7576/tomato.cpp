#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
// M : col

vector<int> map[1000];
int visited[1000][1000];
int mindays;
int bfs(vector<pair<int, int> > p)
{
    const int vSize = p.size();
    //printf(">>>>> vSize : %d\n", vSize);
    int row[vSize];
    int col[vSize];
    int step[vSize];
    int cnt[vSize];
    queue<pair<int, int> > q;
    queue<int> dayq;
    int ret;
    for (int in = 0; in < vSize; in++)
    {
        row[in] = p[in].first;
        col[in] = p[in].second;

        step[in] = 0;
        cnt[in] = 0;
        q.push(p[in]);
        dayq.push(step[in]);
        visited[row[in]][col[in]] = 1;
    }
    while (!q.empty())
    {

        for (int ix = 0; ix < vSize; ix++)
        {
            if (!q.empty())
            {
                pair<int, int> current = q.front();
                ret = step[ix] = dayq.front();
                //printf("curent > [%d][%d] > step[%d] : %d, cnt[%d] : %d\n", current.first, current.second, ix, step[ix], ix, cnt[ix]);
                q.pop();
                
                dayq.pop();

                int dRow[] = {1, 0, -1, 0};
                int dCol[] = {0, 1, 0, -1};

                for (int i = 0; i < 4; i++)
                {

                    int nextRow = current.first + dRow[i];
                    int nextCol = current.second + dCol[i];

                    if (-1 < nextRow && nextRow < N && -1 < nextCol && nextCol < M)
                    {
                        if (map[nextRow][nextCol] == -1)
                        {
                            cnt[ix]++;
                            //printf("Invalid Value  > [%d][%d] cnt[%d] : %d \n", nextRow, nextCol, ix, cnt[ix]);
                            visited[nextRow][nextCol] = 1;
                            
                        }
                        if (map[nextRow][nextCol] == 0 && visited[nextRow][nextCol] == 0)
                        {
                            cnt[ix]++;
                            //printf("next > [%d][%d] cnt[%d] : %d  \n", nextRow, nextCol, ix, cnt[ix]);
                            q.push(make_pair(nextRow, nextCol));
                            dayq.push(step[ix] + 1);
                            visited[nextRow][nextCol] = 1;
                            map[nextRow][nextCol] = -2;
                        }
                    }
                }
            }
        }
    }
    return ret;
}
int main()
{

    scanf("%d %d", &M, &N);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            int temp;
            scanf("%2d", &temp);
            map[i].push_back(temp);
        }
    }
    // for (int i = 0; i < N; i++)
    // {
    //     for (int j = 0; j < M; j++)
    //     {
    //         printf("%d", map[i][j]);
    //     }
    //     cout << endl;
    // }
    vector<pair<int, int> > startVec;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (map[i][j] == 1)
            {
                startVec.push_back(make_pair(i, j));
            }
        }
    }

    int steps = bfs(startVec);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (map[i][j] == 0)
            {
                printf("-1\n");
                return 0;
            }
        }
    }
    printf("%d\n", steps);
}