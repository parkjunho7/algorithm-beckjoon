#include <iostream>

using namespace std;
int calculateCount(int N){
    if(N == 1) return 1;

    return (2*calculateCount(N-1)) + 1;
}
void moveDisk(int from, int to, int via, int N){
    if(N == 1){
        printf("%d %d\n", from, to); 
        return;
    }
    moveDisk(from, via, to, N-1);
    printf("%d %d\n", from, to); 
    moveDisk(via, to, from, N-1);

}

int main(){
    int N;// number of disks
    int count = 0;
    scanf("%d", &N);
    int ret = calculateCount(N);
    printf("%d\n", ret);
    moveDisk(1, 3, 2, N);
    // printf("%d", count);
}