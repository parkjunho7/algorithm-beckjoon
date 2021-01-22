#include <iostream>

using namespace std;

#define MAXNUM 1000000000;

int main()
{
    unsigned int N;
    scanf("%d", &N);

    int quotient;
    int remainder;
    
    quotient = (N) / 6;
    remainder = (N) % 6;
    // printf("Quotient : %d\n", quotient);
    // printf("remainder : %d\n", remainder);
    int count = 0;
    int ret = -1;
    if (N == 1)
    {
        printf("1\n");
    }else
    {
        int a1 = 1;
        int b1 = 1;
        int temp = a1 + b1;
        int n = 1;
        while (true)
        {
            temp = temp + (6*n);
            // printf("temp : %d\n", temp);
            if(temp == N){
                printf("%d\n", n+1+1);
                break;
            }
            if(temp > N){
                printf("%d\n", n+1);
                break;
            }
            n++;
        }
        // if(remainder == 0)
        //     printf("%d\n", i);
        // else printf("%d\n", i+1);
    }
}