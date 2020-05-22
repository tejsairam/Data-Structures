/*
    Check whether the given expression has balanced paranthesis or not
    ( ( a + b ) + ( c * d ) ) ---> correct
    ( ( ( ) ) ) (  ----> wrong
    
    Input:- [ ( ) ]                                            Input:- [ ( ] )                                        Input:- ( ( ( )
    Output:- Balanced                                          Output:-  not Balanced                               Output:- not Balanced


*/

#include <iostream>
#include<stack>
using namespace std;

bool checkExpression(string expr){
    stack<char> st;
    
    //Traversing the expression
    for(int i = 0; i < expr.size(); i++) {
        char newChar = expr[i];
        if(newChar == '(' || newChar == '[' || newChar == '{') {
            st.push(newChar);
        }

        else if(newChar == ')') {
            if(st.empty() || st.top() != '('){
                return false;
            }
            st.pop();
        }

        else if(newChar == ']') {
            if(st.empty() || st.top() != '['){
                return false;
            }
            st.pop();
        }

        else if(newChar == '}') {
            if(st.empty() || st.top() != '{'){
                return false;
            }
            st.pop();
        }
    }
    return st.empty();
}

int main() {
    string expr;
    cin >> expr;

    bool isValid = checkExpression(expr);
    cout << isValid <<endl;
}
