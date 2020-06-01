#include<iostream>
#include<stack>
using namespace std;

void transfer(stack<int>& s1, stack<int>& s2, int n) {
    for(int i = 0; i < n; ++i) {
        s2.push(s1.top());
        s1.pop();
    }

}

void reverseStack(stack<int>& st) {
    int n = st.size();
    for(int i = 0; i < n; ++i) {

         //take an extra temporary stack
            stack<int> temp;

        //put the top element in a variable
            int top_element = st.top();

        //pop the element
            st.pop();

        //transfer the remaining elements to temporary stack
            transfer(st, temp, n - i - 1); //n-i-1 elements means for every iteration transfering remaining elements

        //push top element stores in variable int stack
            st.push(top_element);

        //transfer back the remaining elements from temporary stack
            transfer(temp, st, n - i - 1);
    }
    
}
int main() {
    stack<int> st;

    int n;
    cin >> n;
    //inserting in stack
    for(int i = 0; i < n; ++i ) {
        int temp;
        cin >> temp;

        st.push(temp);
    }

    //printing the stack before reversing
    stack<int> s;
    s = st;
    cout << "Stack before reversing: ";
    while(!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;

    //reversing the stack
    reverseStack(st);

    //printing the stack after reversing
    cout << "Stack after reversing: ";
    while(!st.empty()) {
        cout << st.top() <<" ";
        st.pop();
    }

    return 0;

}
