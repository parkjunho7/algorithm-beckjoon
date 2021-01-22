#include <iostream>
#include <vector>

using namespace std;

int main(){
    int X;
    scanf("%d", &X);
    vector<int> memo;    
    int sum=0;
    int count=0;
    if(X == 1){
        printf("1/1\n");
        return 0;
    } 
    while(sum < X){
        sum = sum + count;
        memo.push_back(sum);
        X--;
        count++;
    }
    int start = memo[count-2];
    int deference = X - start;
   // printf("sum : %d, count : %d, defer : %d\n", sum, count, deference);
    int upper, down;
    upper = count - deference;
    down = 1+ deference;
    if(count % 2 !=0){
        //down
            upper = count - deference;
            down = 1+ deference;
    }else{
        //up
            upper = 1+ deference;
            down = count - deference;
    }
    printf("%d/%d\n", upper, down);

}