#include <iostream>

using namespace std;

struct Node{
    int number;
    Node *next;
};

struct MyQ{
    Node *front;
    Node *rear;
    int nodeCount;
};

class CardGame{
    private:    MyQ cardQ;
    public:
        CardGame(){
            cardQ.nodeCount = 0;
        }
        void pop(){
            if(cardQ.front->next == NULL) printf("%d\n",cardQ.rear->number);
            else{
                Node *node = cardQ.front;
                cardQ.front = cardQ.front->next;
                delete node;
                cardQ.nodeCount--;
            }
        }
        void frontToRear(){
            if(cardQ.front->next == NULL) printf("%d\n",cardQ.rear->number);
            else{
                Node *node = cardQ.front;
                cardQ.front = node->next;
                node->next = NULL;
                cardQ.rear->next = node;
                cardQ.rear = node;
            }
        }
        void runGame(){
            if(cardQ.nodeCount == 1) printf("%d\n", cardQ.front->number);
            while(cardQ.nodeCount > 1){
                this->pop();
                this->frontToRear();
            }
        }
        void push(int n){
            for(int i=1; i<=n; i++){
                Node *node = new struct Node();
                node->number = i;
                node->next = NULL;
                if(cardQ.nodeCount == 0){
                    cardQ.front = node;
                }else{
                    cardQ.rear->next = node;
                }
                cardQ.rear = node;
                cardQ.nodeCount++;
            }
        }
};

int main(){
    int N;
    scanf("%d", &N);
    CardGame game;
    game.push(N);
    game.runGame();
}