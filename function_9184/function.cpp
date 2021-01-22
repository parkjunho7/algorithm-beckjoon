#include <iostream>
#include <map>
#include <string>

using namespace std;

map <string, int> m;
int W(int a, int b, int c){
    if(a<=0 || b<=0 || c<=0) return 1;

    if(a >20 || b > 20 || c > 20) return W(20, 20, 20);

    char temp[16]={0};
    sprintf(temp, "%d_%d_%d", a, b, c);
    //  printf("%s\n", temp);
    if(a < b && b < c){
        if(m.find(temp) != m.end()) return m[temp];
        
        int ret = W(a, b, c-1) + W(a, b-1, c-1) - W(a, b-1, c);
        m.insert(make_pair(temp, ret));
        return ret;
    } 
    else{
        if(m.find(temp) != m.end()) return m[temp];
        
        int ret = W(a-1, b, c) + W(a-1, b-1, c) + W(a-1, b, c-1) - W(a-1, b-1, c-1);
        m.insert(make_pair(temp, ret));
        return ret;
    } 

}

int main(){
    int a, b, c;
    while(true){
        scanf("%3d%3d%3d", &a, &b, &c);
        
        if(a== -1 && b == -1 && c == -1) break;

        printf("w(%d, %d, %d) = %d\n", a, b, c, W(a, b, c));
    }
}