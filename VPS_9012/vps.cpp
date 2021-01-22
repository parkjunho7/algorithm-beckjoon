#include <iostream>
#include <stack>
#include <string>
#include <stdio.h>

using namespace std;

int findVPS(string str){
    stack<int> s;
    char cstr[str.size() + 1];
    strcpy(cstr, str.c_str()); 
    for(int i=0; i<str.size(); i++){
        if(cstr[i] == '('){
            s.push(1);
        }else if( cstr[i] == ')'){
            if(s.size() == 0)
                return 0;
            
            s.pop();
        }
    }

    if(s.size() != 0) return 0;
    if(s.size() == 0) return 1;

    return -1;
}

int main(){
    int T;
    cin >> T;
    string input;
    int ret[T];
    for(int i=0; i<T; i++){
        cin >> input;
        ret[i] = findVPS(input);   
    }
    
    for(int i=0; i<T; i++){
        if(ret[i] == 0)
            printf("NO\n");
        else if(ret[i] == 1)
            printf("YES\n");
    
    }
}