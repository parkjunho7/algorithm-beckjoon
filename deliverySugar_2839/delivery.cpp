#include <iostream>

using namespace std;
#define MIN(a,b) (a < b ? a : b)
int calWith3(int N){
    //28 6+2 = 8
    //28 1+5 = 6
    int remain = N%3;
    // printf("3-remain : %d\n", remain);
    if(remain == 0 ){
        return N / 3;
    }else if(remain == 2){
        if(N<5) return -1;
        return (N-5)/3 + 1;
    }else if(remain == 1){
        if(N<10) return -1;
        return (N-10)/3 + 2;
    }
    return -1;
}
int calWith5(int N){
    //28 6+2 = 8
    //11 5 5 1 
    //31
    int remain = N%5;
    // printf("5-remain : %d\n", remain);
    if(remain == 0 ){
        return N / 5;
    }else if(remain == 1){
        if(N<5) return -1;
        return (N-6)/5 + 2;
    }else if(remain == 2){
        if(N<12) return -1;
        return (N-12)/5 + 4;
    }
    else if(remain == 3){
        if(N<3) return -1;
        return (N-3)/5 + 1;
    }else if(remain == 4){
        if(N<9) return -1;
        return (N-9)/5 +3;
    }
    return -1;
}

int main(){
    int N;
    scanf("%d", &N);
    int ret1, ret2;
    ret1 = calWith3(N);
    ret2 = calWith5(N);
    if(ret1 == -1 && ret2 == -1) printf("-1\n");
    else{
        if(ret1 == -1) printf("%d\n", ret2);
        else if(ret2 == -1) printf("%d\n", ret1);
        else{
            printf("%d\n", MIN(ret1, ret2));
        }
    }
    // printf("with3 : %d\n", calWith3(N));
    // printf("with5 : %d\n", calWith5(N));
    
}