#include <iostream>

using namespace std;

int main(){
    int A, B, V;

    scanf("%d %d %d", &A, &B, &V);
    int beforeDayTarget = V - B;
    int onDayDistance = A - B;
    int temp = beforeDayTarget / onDayDistance;
    if(beforeDayTarget % onDayDistance == 0)printf("%d\n", temp);
    else printf("%d\n", temp +1);

}