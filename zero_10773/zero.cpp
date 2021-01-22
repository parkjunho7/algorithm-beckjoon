#include <iostream>
#include <vector>

using namespace std;

class MyStack{
    private:
        vector<unsigned int> stack;

    public:
        void push(unsigned int value);
        void pop();
        int getSize();
        int getValue(int index);

};
void MyStack::push(unsigned int value){
    this->stack.push_back(value);
}
void MyStack::pop(){
    this->stack.pop_back();
}
int MyStack::getSize(){
   return this->stack.size(); 
}
int MyStack::getValue(int index){
   return this->stack[index]; 
}
int main(){
    int K;
    cin >> K;
    unsigned int input;
    MyStack myStack;
    for(int i=0; i<K; i++){
        cin >> input;
        if(input == 0) myStack.pop();
        else myStack.push(input);
    }
    long long sum = 0;
    for(int i=0; i<myStack.getSize(); i++){
        sum+=myStack.getValue(i);
    }
    cout << sum << endl;
}
