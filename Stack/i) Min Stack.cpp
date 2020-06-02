Implement Min stack using push, pop, top, getMin 

 

Sol:-  We can use 2 stacks 

 

3  5  2  1   0                                                                                         0 

 

For get Min, print the top most element of Min stack 

 

 

class MinStack { 
    private: 
        stack<int> elementStack; 
        stack<int> minimumStack; 
        int minElement = -1; 
    public: 
        void push(int x) { 
            elementStack.push(x); 
            if(elementStack.size() == 1 || x <= minElement) { 
                minimumStack.push(x); 
                minElement = x; 
            }  
        } 
 

void pop() { 
            if (elementStack.top() == minElement) { 
                minimumStack.pop(); 
                if (!minimumStack.empty()) { 
                    minElement = minimumStack.top(); 
                } else { 
                    minElement = -1; 
                } 
            } 
            elementStack.pop(); 
        } 
 

int top() { 
            if (elementStack.empty()) return -1; 
            return elementStack.top(); 
        } 
 

int getMin() { 
            return minElement; 
        } 
}; 

 

 

Sol2:-  Optimising the above approach as it takes extra space 

 

To get the minimum element at any current point i.e what is the top of the stack and what is the current minimum. 

 

Top < curr_min  ====>>> top - curr_min < 0   So there is a possibilty of negative number. 

So, 

2 * top < 2 * curr_min ====>>>  2 * top - curr_min < curr_min 

 

Instead of pushing top I will push(2*top - curr_min ) 

 

Let us take an example  3  5  2  1  7  -1 

 

First pushing 3 into stack and it is the curr minimum 

Now checking if 5 is < curr minimum. As it is greater push 5 into stack 

Checking 2 with curr minimum. 2 is smaller than 3. 

So instead of pushing 2, push 2*new element - curr_min 

i.e 2*2 - 3 = 1 . So, push( 1 ) and update curr minimum 

This is because we can extract the curr minimum easily  

 

-1 less than curr min, 

2*-1 - 2 = -4  

 

When the new element < curr_min push then this element is new minimum 

   x --> 2 * new minimum - old minimum 

So, 

Old minimum --> 2 * new minimum - x 

 

While Popping, how to realise the update? 

When top of stack which is going to be popped is less than curr minimum we will pop the stack and update curr minimum using  Old minimum --> 2 * new minimum - x 

 

Let us dry run,   3  5  2  1  1  -1                                                 

 

Old minimum = 3   2   1   -1 

 

New minimum = 2 we will push this in stack  2*2 -3 = 1  

 

New minimum = 1 we will push 2*1-2 = 0  

 

Next element is also 1 so it is not less than anything. So, we will just 

Push it. 

           

New minimum = -1 we will push 2*-1 - 1 = -3   

 

If we call get min we will return -1 I.E OLD MINIMUM 

 

Whenever we do pop of the stack check if top of the stack is less than old minimum 

Updating old minimum = 2 * new minimum - x 

2 * -1  - (-3) = 1 = new minimum 
