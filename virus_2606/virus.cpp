#include <iostream>
#include <vector>

using namespace std;

#define MAXNODE 101
int Node;
int Edge;

//vector<int> map[MAXNODE+1];
vector<vector<int> > map;
bool visited[MAXNODE] = {false};
int virusCount = 0;

void dfs(int start){

    //printf("visited [%d] \n", start);
    virusCount++;
    visited[start] = true;
    for(int i=0; i<map[start].size(); i++){
       
        int next = map[start][i];
        if(visited[next] == false){
            dfs(next);
        }
    }
    
}

int main(){

    scanf("%d", &Node);
    scanf("%d", &Edge);
    map.resize(Node + 1);
    int tempRow, tempCol;
    for(int i=0; i<Edge; i++){
        
        scanf("%d %d", &tempRow, &tempCol);
        map[tempRow].push_back(tempCol);
        map[tempCol].push_back(tempRow);
    }
    // int n, from, to;
    // scanf("%d %d", &Node, &n);
    // map.resize(Node + 1);
    // for (int i = 0; i < n; i++)
    // {
    //     scanf("%d %d", &from, &to);
    //     map[from].push_back(to);
    //     map[to].push_back(from);
    // }
 
    dfs(1);
    printf("%d\n", virusCount-1);
}