#include <iostream>
#include <vector>

using namespace std;

#define max(a, b) ( a >  b ? a : b)

int N;
int stair[301];
int dp[301];

int main(){
    scanf("%d", &N);

    for(int i=1; i<=N; i++){
        int temp;
        scanf("%d", &temp);
        stair[i] = temp;
    }
    
    dp[1] = stair[1];
    dp[2] = stair[1] + stair[2];
    dp[3] = max(stair[3]+ stair[2], stair[3] + dp[1]);

    for(int i=4; i<= N; i++){
        dp[i] = max(stair[i] + stair[i-1] + dp[i-3], 
                stair[i]+ dp[i-2] );
    }
    printf("%d", dp[N]);


}