#include <iostream>
#include <string.h>

using namespace std;

int main(){
    char A[10000+2];
    char B[10000+2];
    char C[10000+2];
    C[10001] = '\0';

    scanf("%s %s", A, B);
    int aidx;
    int bidx;
    while(true){
        if(A[aidx] != '\0') aidx++;
        else break;
    }
    while(true){
        if(B[bidx] != '\0') bidx++;
        else break;
    }

    // printf("Aidx : %d, Bidx : %d\n", aidx, bidx);
    int lastAidx = aidx-1;
    int lastBidx = bidx-1;
    int Cidx = lastAidx < lastBidx ? lastBidx : lastAidx;
    int upperNum=0;
    int sum=0;
    while(true){
        if(lastAidx < 0 && lastBidx < 0) {
            if(upperNum == 1){
                char buff[10000+2];
                buff[0] = 1 + '0';
                strcat(buff, C);
                printf("%s\n", buff);
                return 0 ;
            }
            break;
        }
        if(lastAidx < 0 && lastBidx >= 0){
            sum =  B[lastBidx--] - '0';
        }
        else if(lastBidx < 0 && lastAidx >=0){
            sum =  A[lastAidx--] - '0';
        }else{

            sum = A[lastAidx--] + B[lastBidx--] - '0' - '0';
        }

        if(upperNum == 1){
            sum+=1;
            upperNum = 0;
        }

        if((sum) >= 10){
            upperNum = 1;
            C[Cidx] = sum%10 + '0';
        }else{
            upperNum = 0;
            C[Cidx] = sum + '0';
        }
        Cidx--;

    }
    printf("%s\n", C);
}