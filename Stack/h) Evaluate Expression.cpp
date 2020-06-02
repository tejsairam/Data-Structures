
/*

Problem Description

An arithmetic expression is given by a charater array A of size N. Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or operator.



Problem Constraints
1 <= N <= 105



Input Format
The only argument given is character array A.



Output Format
Return the value of arithmetic expression formed using reverse Polish Notation.



Example Input
Input 1:
    A =   ["2", "1", "+", "3", "*"]
Input 2:
    A = ["4", "13", "5", "/", "+"]


Example Output
Output 1:
    9
Output 2:
    6


Example Explanation
Explaination 1:
    starting from backside:
    * : () * ()
    3 : () * (3)
    + : (() + ()) * (3)
    1 : (() + (1)) * (3)
    2 : ((2) + (1)) * (3)
    ((2) + (1)) * (3) = 9
Explaination 2:
    + : () + ()
    / : () + (() / ())
    5 : () + (() / (5))
    1 : () + ((13) / (5))
    4 : (4) + ((13) / (5))
    (4) + ((13) / (5)) = 6
    
*/

int Solution::evalRPN(vector<string> &A) {
    
    stack<int> st;
    
    for(int i = 0; i < A.size(); ++i ) {
       
        
        if(A[i] == "+" || A[i] == "-" || A[i] == "*" || A[i] == "/") {
            int x1 = st.top();
            st.pop();
            int x2 = st.top();
            st.pop();
            
            if(A[i] == "+") {
                st.push(x1 + x2);
            }
            else if(A[i] == "-") {
                st.push(x2 - x1);
            }
            else if(A[i] == "*") {
                st.push(x1 * x2);
            }
            else {
                st.push(x2 / x1);
            }
            
        }
        else {
                st.push(atoi(A[i].c_str()));
            }
    }
    return st.top();
}

    
    
