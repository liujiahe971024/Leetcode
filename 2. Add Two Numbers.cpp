/*
Jiahe Liu
liujiahe971024@gmail.com
09/21/2019

2. Add Two Numbers
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
------------------------------------------------------
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum = 0, last = 0;
        ListNode *list1 = new ListNode(0);
        ListNode *list = list1;
        bool mark = false;
        while(l1 != NULL || l2 != NULL || mark){
            if(l1 != NULL && l2 != NULL){
                 sum = l1->val + l2->val + last;
                l1 = l1->next;
                l2 = l2->next;
            }
            else if (l1 == NULL && l2 != NULL){
                sum = l2->val + last;
                l2 = l2->next;
            }
            else if (l1 != NULL && l2 == NULL) {
                sum = l1->val + last;
                l1 = l1->next;
            }
            else sum = last;
            if(sum >= 10){
                last = 1;
                sum = sum - 10;
                mark = true;
            }
            else{
                mark = false;
                last = 0;
            }
            
            list->next = new ListNode(sum);
            list = list->next;
            
        }
        
        return list1->next;
        
    }
};