/*

Reverse a Stack using Recursion. Do not use any extra stack.

Input Format
First line contains an integer N (size of the stack).
Next N lines follow each containing an integer to be stored in the stack where the last integer is at the top of the stack.

Constraints
1 <= N <= 10^4

Output Format
Output the values of the reversed stack with each value in one line each.

Sample Input
3
3
2
1

Sample Output
3
2
1

Explanation
Original Stack = [ 3 , 2 , 1 ] <-TOP
Reverse Stack = [ 1 , 2 , 3 ] <-TOP

*/

#include<iostream>
#include<stack>
using namespace std;

void insertAtBottom(stack<int>& s, int x) {
    if(s.empty()){
        s.push(x);
        return;
    }

    int y = s.top();
    s.pop();
    insertAtBottom(s, x);
    s.push(y);

}

void reverseStackRec(stack<int>& s) {
    if(s.empty()) return;

    int x = s.top();
    s.pop();
    reverseStackRec(s);
    insertAtBottom(s, x);
}

int main() {
    int N;
    cin >> N;

    stack<int> st;
    for(int i = 0; i < N; ++i) {
        int temp;
        cin >> temp;
        st.push(temp);
    }

    reverseStackRec(st);

    while(!st.empty()) {
        cout<<st.top()<<endl;
        st.pop();
    }
}
