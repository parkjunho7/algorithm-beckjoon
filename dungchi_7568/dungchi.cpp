#include <iostream>
#include <vector>

using namespace std;

typedef enum {
    NOTDUNGCHI = 0,
    DUNGCHI = 1,
    DEFFER, 
    ERROR = -1
}DUNGCHIENUM;

int compare(pair<int, int> a, pair<int, int> b){
    if(a.first > b.first && a.second > b.second) return NOTDUNGCHI;
    if((a.first > b.first && a.second < b.second) || (a.first < b.first && a.second > b.second)) return DEFFER;
    if(a.first < b.first && a.second < b.second) return DUNGCHI;

    return ERROR;
}

int main(){
    int N;

    scanf("%d", &N);
    pair<int, int> people[N];
    for(int i=0; i<N; i++){
        int weight;
        int height;
        scanf("%d %d", &weight, &height);
        people[i] = make_pair(weight, height);
    }

    vector< int > rating;

    for(int i=0; i<N; i++){
        int ratingIdx = 1;
        for(int j=0; j<N; j++){
            if(i == j) continue;

            int ret = compare(people[i], people[j]);
            switch(ret){
                case DUNGCHI :
                    ratingIdx++;
                    break;
                case NOTDUNGCHI:
                    break;
                case DEFFER:
                    break;
            }
        }
        rating.push_back(ratingIdx);
    }

    for(int i=0; i<rating.size(); i++){
        printf("%d ", rating[i]);
    }
}