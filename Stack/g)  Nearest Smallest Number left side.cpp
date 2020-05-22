/*
   We are given an array 1  6  4  10  2  5 -7 . What is the nearest smallest element on the left side ?
   Output:-  G  1  1  4  1  2  G

   G->garbage

   Using stacks, initially we have empty stack
   At any time,  if we have stack empty there is no element less on left side i.e we put a garbage value.
*/

#include<iostream>
#include<stack>
using namespace std;

void smallestElementLeft(int arr[],int n){
    stack<int> st;
    
    for(int i = 0; i < n; ++i) {
        while(!st.empty() && st.top() >= arr[i]){
            st.pop();
        }

        if(st.empty()){
            cout << "_" << " ";
        }
        else{
            cout << st.top() << " ";
        }
        st.push(arr[i]);
    }
}

int main() {
    int N;
    cin>>N;

    int arr[N];
    for(int i=0;i<N;i++){
        cin>>arr[i];
    }

    smallestElementLeft(arr,N);
}
