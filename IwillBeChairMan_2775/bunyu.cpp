#include <iostream>

using namespace std;

int calDownstairPop(int k, int n, int **stair){
    int sum=0;
    for(int i=1; i<=n; i++){
        sum += stair[k-1][i];
    }
    return sum;
}

int calculatePop(int k, int n, int **stair ){
    for(int i=1; i<=n; i++)
        stair[0][i] = i;

    for(int i=1; i<=k; i++){
        for(int j=1; j<=n; j++){
            stair[i][j]=calDownstairPop(i, j, stair);
            // printf("stair [%d][%d] : %d\n", i, j, stair[i][j]);
        }
    }
    return stair[k][n];
}

int main(){
    int T, k, n;
    scanf("%d", &T);
    for(int i=0; i<T; i++){
        scanf("%d", &k);
        scanf("%d", &n);
        int **stair;
        stair = new int *[k+1];
        for(int j=0; j<k+1; j++)
            stair[j] = new int[n+1];

        int ret = calculatePop(k, n, stair);
        printf("%d\n", ret);

    }
}