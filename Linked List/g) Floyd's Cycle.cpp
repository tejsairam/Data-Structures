List Cycle
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

Try solving it using constant additional space.

Example :

Input : 

                  ______
                 |     |
                 \/    |
        1 -> 2 -> 3 -> 4

Return the node corresponding to node 3. 


Given a linked list, check if it contains a cycle or not

 Take 2 pointers fast and slow 
 at some point if they meet then Linked List contains a cycle
 
 /**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
ListNode* Solution::detectCycle(ListNode* A) {
    
    ListNode* slow = A;
    ListNode* fast = A;
    bool isCycle = false;
    
    while(fast != NULL && fast -> next != NULL) {
        fast = fast -> next -> next;
        slow = slow -> next;
        
        if(fast ==  slow) 
        {
            isCycle = true;
            break;
        }
        
    }
    
    if(isCycle == false) {
        return NULL;
    }
    
    slow = A;
    while(fast != slow) {
        fast = fast ->next;
        slow = slow -> next;
        
    }
    return slow;
            
}
