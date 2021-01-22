#include <iostream>
#include <vector>

using namespace std;

int N;

vector<pair<int, int> > memo[41];
bool visit[41];

pair<int, int> dfs(int currentIndex){
  
    if(visit[currentIndex] == true) 
        return memo[currentIndex][0];

    visit[currentIndex] = true;
    
    memo[currentIndex-1].push_back(dfs(currentIndex-1));
    memo[currentIndex-2].push_back(dfs(currentIndex-2));
    
    int sumFirst = memo[currentIndex-1][0].first + memo[currentIndex-2][0].first;
    int sumSecond = memo[currentIndex-1][0].second + memo[currentIndex-2][0].second;
    pair<int, int> p = make_pair(sumFirst, sumSecond);
    memo[currentIndex].push_back(p);
    return p;
    
    // return make_pair(memo[currentIndex-1][0].first + memo[currentIndex-2][0].first,
    //                  memo[currentIndex-1][0].second + memo[currentIndex-2][0].second);

}

int main(){
    memo[0].push_back(make_pair(1, 0));
    memo[1].push_back(make_pair(0, 1));
    memo[2].push_back(make_pair(1, 1));

    visit[0] = true;
    visit[1] = true;
    visit[2] = true;
    
    scanf("%d", &N);
    int numList[N+1];
    for(int i=0; i<N; i++){
        scanf("%d", &numList[i]);
        pair<int, int> ret =  dfs(numList[i]);
        printf("%d %d\n", ret.first, ret.second);
    }

}
