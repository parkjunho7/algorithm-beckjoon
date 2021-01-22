#include <iostream>
#include <cstring>

using namespace std;
#define chA 65;

typedef struct Dial{
    int number;
    int time;
    char ch[5];

}Dial;

int main(){

    char input[16] = {0};
    scanf("%s", input);
    char *ptr = input;
    Dial dialArr[10];
    char current = chA;

    for(int i=1; i<=9; i++){
        memset(dialArr[i].ch, 0x00, sizeof(char)*5);
        if(i==1){
            dialArr[i].number = 1;
            dialArr[i].time = 2;
            continue;
        }
        dialArr[i].number = i;
        dialArr[i].time =i+1;
        if(dialArr[i].number == 7 || dialArr[i].number == 9){
            for(int j=0; j<4; j++){
                dialArr[i].ch[j] = current++;
            }
        }else{
            for(int j=0; j<3; j++){
                dialArr[i].ch[j] = current++;
            }
        }
    }
    int timeForDial = 0;
    while(*ptr != '\0'){
        for(int i=1; i<=9; i++){
            int j=0;
            while(dialArr[i].ch[j] != '\0'){
                if(*ptr == dialArr[i].ch[j]){
                    // printf("num : %d, time : %d\n", dialArr[i].number, dialArr[i].time);
                    // printf("%c\n", dialArr[i].ch[j]);
                    //    printf("\n");
                    timeForDial += dialArr[i].time;
                    ptr++;
                    break;
                }
            
                j++;
            }
        }
    }
    printf("%d\n", timeForDial);
}