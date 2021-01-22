#include <iostream>
#include <vector>

using namespace std;

struct CircularQueue{
    struct Node * front;
    struct Node * rear;
    int qCount;
};

struct Node{
    int number;
    struct Node * next;
};
class Yosepus{
    private:
        CircularQueue myQ;
        vector<int> result;
        int firstFlag;
        int n,k;
    public:
        Yosepus(int N, int K){
            myQ.qCount = 0;
            k = K;
            n = N;
            firstFlag = 1;
        }
        void push(int n){
            for(int i=0; i<n; i++){
                struct Node *newNode = new struct Node();
                newNode->number = i+1;
                if(myQ.qCount == 0){
                    myQ.front = newNode;
                }else if(myQ.qCount == n-1){
                    myQ.rear->next = newNode;
                    newNode->next = myQ.front;
                }else{
                    myQ.rear->next = newNode;
                }
                myQ.rear = newNode;
                myQ.qCount++;
            }
        }
        void popAndChangeFront(){
            int num = k-1;
            while(num > 0){
                if(myQ.front->next == NULL) break;
                myQ.front = myQ.front->next;
                myQ.rear = myQ.rear->next;
                num--;
            }
            struct Node *popNode = myQ.front;
            result.push_back(popNode->number);
            myQ.front = myQ.front->next;
            myQ.rear->next = myQ.front;
            delete popNode;
            myQ.qCount--;
        }
        void runYosepus(){
            this->push(n);
            for(int i=0; i<n; i++){
                this->popAndChangeFront();
            }
            
            printf("<");
            for(int i=0; i<n; i++){
               printf("%d", result[i]);
               if(i != n-1)
                printf(", ");
            }
            printf(">\n");
            
        }
};
int main(){
    int N, K;
    scanf("%d %d", &N, &K);
    Yosepus yo(N, K);
    yo.runYosepus();
}