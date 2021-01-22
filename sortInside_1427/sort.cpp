#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void swap(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 
  
int partition (int arr[], int low, int high) 
{ 
    int pivot = arr[high];  
    int i = (low - 1);  
  
    for (int j = low; j <= high- 1; j++) 
    { 
        if (arr[j] >= pivot) 
        { 
            i++;    
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1); 
} 
  
void quickSort(int arr[], int low, int high) 
{ 
    if (low < high) 
    { 
        int pi = partition(arr, low, high); 
        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
    } 
} 
int main(){
    string str;
    cin >> str;
    int strSize = str.size();
    // cout << strSize << endl;
    // cout << "string : " << str << endl;
    int intArr[strSize];
    char charArr[strSize];
    char temp;
    
    for(int i=0; i<strSize; i++){
        temp = str[i];
        intArr[i] = atoi(&temp);
        cout << intArr[i] << endl;
        //charArr[i] = temp;
    }
    quickSort(intArr,0, strSize-1);
    //sort(charArr, charArr+strSize);

    for(int j=0; j<strSize; j++)
        printf("%d", intArr[j]);
    
    printf("\n");
}

