/*
    Check whether the given expression has balanced paranthesis or not
    ( ( a + b ) + ( c * d ) ) ---> correct
    ( ( ( ) ) ) (  ----> wrong

*/

#include<iostream>
#include<stack>
using namespace std;

bool checkExpression(string str){
    stack<char> s;

    for(int i = 0; i < str.size(); i++){
        char currChar = str[i];
        stack<char> s;
        if(currChar == '('){
            s.push(currChar);
        }
        else if(currChar == ')'){
            if(s.empty() || s.top() != '('){
                return false;
            }
            s.pop();
        }
    }
    return s.empty();
}

int main(){
    string expr;
    cin>>expr;

    bool isValid = checkExpression(expr);
    cout << isValid << endl;

    return 0;
}
