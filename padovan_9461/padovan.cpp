#include <iostream>

using namespace std;



long long padovan(int start, long long MEMO[]){
    if(start <= 3) return 1;
    if(MEMO[start] != 0)
        return MEMO[start];

    MEMO[start-2] = padovan(start -2, MEMO); 
    MEMO[start-3] = padovan(start -3, MEMO);

    return MEMO[start-2] + MEMO[start-3];  
}

int main(){
    int T;
    scanf("%d", &T);
    int targetArr[T];

    for(int i=0; i<T; i++){
        int temp;
        scanf("%d", &temp);
        targetArr[i] = temp;
    }
    for(int i=0; i<T; i++){
        long long MEMO[100+1] = {0};
        long long ret = padovan(targetArr[i], MEMO);
        printf("%lld\n", ret);
    }


}