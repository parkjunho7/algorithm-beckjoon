#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<pair<int, int> > room; //start, end

bool compareFirst(pair<int, int> &a, pair<int, int> &b){
    return a.first < b.first;
}
bool compareSecond(pair<int, int> &a, pair<int, int> &b){
    if(a.second == b.second)
        return compareFirst(a, b);
    return a.second < b.second;
}


int ans;
int main(){
    
    scanf("%d", &N);

    for(int i=0; i<N; i++){
        int start, end;
        scanf("%d %d", &start, &end);
        room.push_back(make_pair(start, end));
    }

    sort(room.begin(), room.end(), compareSecond);
    
    int start = room[0].first;
    int end = room[0].second;
    ans++;
    for(int i=1; i<N; i++){

        
        if(end <= room[i].first ){
            ans++;
            end = room[i].second;
        }
    }
    printf("%d\n", ans);
}