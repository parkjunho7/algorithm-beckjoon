#include <iostream>
#include <vector>
#include <queue>

using namespace std;


int N, K;
int visited[100000+1];
int bfs(int position, int steps){
    int MAXSIZE = 100000;

    queue< pair<int, int> > q;
    q.push(make_pair(position, steps));
    while(!q.empty()){
        
        pair<int, int> current = q.front();
        if(current.first == K){
            //printf("GOAL !! current : %d , step : %d \n", current.first, current.second);
            return current.second;
        }
        q.pop();
        //printf("current : %d , step : %d \n", current.first, current.second);
        int dPosition[] = { -1, 1, 2*current.first};
        for(int i=0; i<3; i++){
            int next;
            if(i==2){
                next = dPosition[i];
            }else{
                next = current.first + dPosition[i];
            }
            if(next < MAXSIZE+1 && 0 <= next){

                if(visited[next] == 0){
                    visited[next] = 1;
                    q.push(make_pair(next, current.second+1));
                }
            }
        }
         
    }
    return -1;
}

int main(){
    scanf("%d %d", &N, &K);

    int ret = bfs(N, 0);
    printf("%d\n", ret);
}