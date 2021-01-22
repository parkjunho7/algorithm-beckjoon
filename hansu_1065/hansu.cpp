#include <iostream>

using namespace std;
int getHansuNum(int n){
    if(n < 100){
        return n;
    }else if (n <= 1000){
        // 100 <= n <= 1000 
        char str[4]={0};
        int count = 99;
        for(int i=100; i<=n; i++){
            sprintf(str, "%d", i);
            if(str[1] - str[0] == str[2] - str[1]){
                count++;
            }
        }
        return count;
    }
    return -1;
}
int main(){
    int N;
    scanf("%d", &N);
    int num = getHansuNum(N);
    printf("%d\n", num);
}