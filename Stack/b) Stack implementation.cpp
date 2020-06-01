/* We can generalise the code for all types of data types like integers, strings... using templates */

#include<iostream>
#include<vector>
using namespace std;

template<typename T>
class stack {
    private:
        vector<T> v;
    
    public:
        void push(T data) {
            v.push_back(data);
        }

        bool empty() {
            return v.size()==0;
        }

        void pop() {
            if(!empty()) {
                v.pop_back();
            }
        }

        T top() {
            return v[v.size() - 1];
        }
};

int main() {
    stack<char> s1;

    stack<int> s2;

    
    for(int i=1;i<=7;i++){
        char ch;
        cin >> ch;

        s1.push(ch);
    }

    
    for(int i=1;i<=5;i++) {
        int data;
        cin >> data;

        s2.push(i);
    }

    while(!s1.empty()) {
        cout << s1.top() << " ";
        s1.pop();
    }

    cout << endl;

    while(!s2.empty()) {
        cout << s2.top() << " ";
        s2.pop();
    }

    return 0;
}
