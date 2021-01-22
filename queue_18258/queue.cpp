#include <iostream>
#include <vector>
#include <cstring>
#include <string>

using namespace std;

typedef struct element{
    int * value;
    element * next;        
}Element;
typedef struct myQ{
    Element *front;
    Element *rear;
    int count; 
}MyQ;

class MyQueue{
  private:
    MyQ q;

  public:
    MyQueue(int N){
        q.count = 0;
        q.front = q.rear = NULL;
    }

    void push(int x){
        struct element *newElement = new struct element();
        newElement->value = new int(x);
        if(q.count == 0 ) {
            q.front = newElement;
            q.rear = newElement;
        }
        else{
            q.rear->next = newElement;
        } 
        q.rear = newElement;
        q.count++;
    }
    
    int getSize(){
        return q.count;
    }
    void writeBuffer(int num){
        printf("%d\n", num);
    }
    void pop(){
        if(q.front == NULL || q.count== 0) writeBuffer(-1);
        else{
            writeBuffer(*q.front->value);
            Element *front = q.front;
            q.front = front->next;
            delete front;
            q.count--;
        }
    }

    void printSize(){
        writeBuffer(q.count);
    }
    
    int empty(){
        if(q.count == 0) return 1;
        else return 0;
    }
    
    void front(){
        if(q.count == 0) writeBuffer(-1);
        else writeBuffer(*q.front->value);
    }
    
    void back(){
        if(q.count == 0) writeBuffer(-1);
        else writeBuffer(*q.rear->value);
    }
};

int main(){

    int N;
    scanf("%d", &N);
    MyQueue myq(N);
    char str[8]={0};
    int num;

    for(int i=0; i<N; i++){
        scanf("%s", str);
        switch(str[0]){
            case 'p':
                if(str[1] == 'u'){
                    scanf("%d", &num);  
                    myq.push(num); 
                }else{
                    myq.pop();
                }
            break;
            case 'f':
                myq.front();
            break;
            case 'e':
                printf("%d\n", myq.empty());
            break;
            case 's':
                myq.printSize();
            break;
            case 'b':
                myq.back();
            break;
        }
    }

}