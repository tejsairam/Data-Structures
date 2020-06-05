Palindrome List
Problem Description

Given a singly linked list A, determine if its a palindrome. Return 1 or 0 denoting if its a palindrome or not, respectively.



Problem Constraints
1 <= |A| <= 105



Input Format
The first and the only argument of input contains a pointer to the head of the given linked list.



Output Format
Return 0, if the linked list is not a palindrome.

Return 1, if the linked list is a palindrome.



Example Input
Input 1:

A = [1, 2, 2, 1]
Input 2:

A = [1, 3, 2]


Example Output
Output 1:

 1 
Output 2:

 0 


Example Explanation
Explanation 1:

 The first linked list is a palindrome as [1, 2, 2, 1] is equal to its reversed form.
Explanation 2:

 The second linked list is not a palindrom as [1, 3, 2] is not equal to [2, 3, 1].
 
 
 
 METHOD 1 (Use a Stack)

A simple solution is to use a stack of list nodes. This mainly involves three steps.
Traverse the given list from head to tail and push every visited node to stack.
Traverse the list again. For every visited node, pop a node from stack and compare data of popped node with currently visited node.
If all nodes matched, then return true, else false.
Below image is a dry run of the above approach:


int Solution::lPalin(ListNode* head) {
    stack<int> s;
    int result;
    ListNode* slow = head;
    
    while(slow != NULL) {
        s.push(slow -> val);
        slow = slow -> next;
    }
    
    while(head != NULL) {
        int top_element = s.top();
        s.pop();
        if(top_element != head->val) {
            //result = 0;
            //break;
            return 0;
        }
        head = head -> next;
    }
    //result = 1;
    //return result;
    return 1;
}

