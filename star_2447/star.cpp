#include <iostream>
#include <cstring>

using namespace std;


void basicPattern(int N, int &row, int &col, char *map[]){
    
    for(int i=row; i<row+3; i++){
        for(int j=col; j<col+3; j++){
            if(i == 1 && j == 1){
                map[i][j] = ' ';
                continue;
            }
            map[i][j] = '*';
        }
    }
}
void makePattern(int N, int K, int &row, int &col, char *map[]){


    if(N == K){
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                printf("%c", map[i][j]);
            }
            printf("\n");
        }
        return;
    }
    else{
        char *copiedMap[K*3];
        for(int i=0; i<K*3; i++){
            copiedMap[i] = new char[K*3];
            for(int j=0; j<K*3; j++)
                copiedMap[i][j] = ' ';
        }
        int index=0;
        int threeTimes = K*3;
        for(int i=0; i<threeTimes; i++){
            for(int j=0; j<3; j++){
                if(i >= (threeTimes/3)  && i <= ((threeTimes/3)*2 -1) && j == 1 ) {
                    continue;
                }else{
                    strncpy(&copiedMap[i][j*(threeTimes/3)], map[index], K);
                }
            }
            index++;
            if(index >= threeTimes/3) index = 0;
        }
        for(int i=0; i<K; i++)
            delete[] map[i];

        makePattern(N,threeTimes, row, col, copiedMap);
    }
}
void makeStar(int N, int row, int col ){
    int K=3;
    char *basicMap[3];
    for(int i=0; i<3; i++){
        basicMap[i] = new char[3];
        for(int j=0; j<3; j++)
            basicMap[i][j] = ' ';
    }
 
    basicPattern(N, row, col, basicMap);
    makePattern(N, K, row, col, basicMap);
}

int main(){
    int N;
    scanf("%d", &N);
    makeStar(N, 0, 0);
}