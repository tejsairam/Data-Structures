Remove Duplicates from Sorted List
Problem Description

Given a sorted linked list, delete all duplicates such that each element appear only once.



Problem Constraints
0 <= length of linked list <= 106



Input Format
First argument is the head pointer of the linked list.



Output Format
Return the head pointer of the linked list after removing all duplicates.



Example Input
Input 1:

 1->1->2
Input 2:

 1->1->2->3->3


Example Output
Output 1:

 1->2
Output 2:

 1->2->3


Example Explanation
Explanation 1:

 Each element appear only once in 1->2.
 
 if the given list is not sorted then maintain a visited vector and mark it true for every value and check for the rest
 
 
ListNode* Solution::deleteDuplicates(ListNode* A) {
    ListNode* temp = A;
    
    while(A != NULL) {
        
        while(A -> next != NULL && A -> val == A -> next -> val) {
            A -> next = A -> next -> next;
        }
        A = A -> next;
    }
    return temp;
}
