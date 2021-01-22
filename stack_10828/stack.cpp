#include <iostream>
#include <vector>
#include <string>

using namespace std;

class MyStack{

    private:
        vector<int> v;
        int size;

    public:

        void push(int x){
            v.push_back(x);
            //cout << "push " << x << endl;
        }
        void pop(){
            if(this->empty(1)){
                cout << "-1" << endl;
            }else{
                int value = v[size-1];
                cout << value << endl;
                v.pop_back();
            }
        }
        void showSize(){
            size = v.size();
            cout <<size << endl;
        }
        void showSize(int internal){
            size = v.size();
        }
        void empty(){
            this->showSize(1);
            if(size == 0) cout << "1" << endl;
            else cout << "0" << endl;
            
        }
        int empty(int internal){
            this->showSize(1);
            if(size == 0) return 1;
            else return 0;
            
        }
        void top(){
            if(this->empty(1)){
                cout << "-1" << endl;
            }else{
                cout << v[size-1] << endl;
            }
        }

};

int main(){
    int N;
    scanf("%d", &N);
    string inputStr;
    MyStack stack;
    int value;

    for(int i=0; i<N; i++){
        cin >> inputStr;
        if(inputStr.find("push") != string::npos){
            cin >> value;
            stack.push(value);
        }else if(inputStr.find("top")!= string::npos){
            stack.top();
        }else if(inputStr.find("size")!= string::npos){
            stack.showSize();
        }else if(inputStr.find("empty")!= string::npos){
            stack.empty();
        }else if(inputStr.find("pop")!= string::npos){
            stack.pop();
        }
    }
}