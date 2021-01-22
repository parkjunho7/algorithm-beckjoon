#include <iostream>

using namespace std;

//returns difference
int find3Cards(int cards[], int N, int SUM){
    int minValue = SUM;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(i == j) continue;

            for(int k=0; k<N; k++){
                if(j == k || k == i) continue;

                int cardSum = cards[i] + cards[j] + cards[k];
                if(cardSum > SUM) continue; 
                int absSum = abs(cardSum - SUM);
                if(absSum < minValue)
                    minValue = absSum;

            }
        }
    }
    return minValue;
}

int main(){
    int N, SUM;

    scanf("%d %d", &N, &SUM);
    int cards[N];
    for(int i=0; i<N; i++){
        int temp;
        scanf("%6d", &temp);
        cards[i] = temp;
    }

    // for(int i=0; i<N; i++)
    //     printf("%d ", cards[i]);

    int ret = find3Cards(cards, N, SUM);
    //if(ret > SUM) printf("%d", SUM+ret);
    //else 
    printf("%d\n", SUM - ret);
}