#include <iostream>
#include <vector>

using namespace std;

struct myStack{
    struct Node * front;
    int stackCount;
};
typedef struct Node{
    char ch;
    Node * next;
}Node;

class Balance{
    private:
        myStack s;
        char *str;
        int fault;
    public:
        Balance(char * inputStr){
            s.stackCount = 0;
            str = inputStr;
            fault = 0;            
        }
        void push(char c){
            Node * newNode = new Node();
            newNode->next = NULL;
            newNode->ch = c;
            if(s.stackCount == 0)
                s.front = newNode;
            else
            {
                newNode->next = s.front;
                s.front = newNode;
            }
            s.stackCount++;
        }
        char pop(){
            if(s.stackCount == 0) return '\0';
            Node *front = s.front;
            s.front = s.front->next;
            s.stackCount--;
            char frontCh = front->ch;
            delete front;
            return frontCh;
        }

        void judgeStr(){
            while(*str != '\0'){
                if(*str == '(' || *str == '['){
                    this->push(*str);
                }else if(*str == ')' ){
                    char retCh = this->pop();
                    // printf("## %c\n", retCh);
                    if(retCh == '\0' || retCh != '('){
                        fault = 1;
                        break;
                    }
                }else if(*str == ']' ){
                    char retCh = this->pop();
                    // printf("## %c\n", retCh);
                    if(retCh == '\0' || retCh != '['){
                        fault = 1;
                        break;
                    }
                }
                str++;
            }
            if(fault == 1) printf("no\n");
            else if(s.stackCount == 0 && fault == 0) printf("yes\n");
            else printf("no\n");

        }
};
int main(){
    char input[100+1+1] = {0};
    while(true){

        //scanf("%s", input);
        fgets(input, sizeof(input), stdin);
        if(input[0] == '.')
            break;
            
        Balance bal(input);
        bal.judgeStr();
    }


}