#include <iostream>
#include <algorithm>

using namespace std;

bool compare(int a, int b){
    return a > b;
}
int calculateCoins(int moneyArr[], int size,int price){
    int needCoins = 0;
    for(int i=0; i<size; i++){
        if(price / moneyArr[i] != 0){
            while(price / moneyArr[i] != 0){
                needCoins++;
                //printf("coint : %d, price : %d, needCoin : %d\n",moneyArr[i] ,price, needCoins);
                price = price - moneyArr[i];
            }
        }
    }
    return needCoins;
}
int main(){

    int N, K;

    scanf("%d %d", &N, &K);
    int moneyArr[N];

    int temp;
    for(int i=0; i<N; i++){
        scanf("%d", &temp);
        moneyArr[i] = temp;
    }

    sort(moneyArr, &moneyArr[N], compare);
    int ret = calculateCoins(moneyArr,N, K);
    printf("%d\n", ret);
    // for(int i=0; i<N; i++){
    //     printf("%d ", moneyArr[i]);
    // }
    // printf("\n");
    

}