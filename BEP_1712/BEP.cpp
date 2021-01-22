#include <iostream>

using namespace std;

int main(){
    long long A, B, C;
    scanf("%lld %lld %lld", &A, &B, &C);
    
    if (C == B) {
        printf("%d", -1); 
        return 0;
    }
    long long n = A / (C - B);
    if((C - B) <= 0) {
        printf("-1");
        return 0;
    }
    printf("%lld", n+1);
}