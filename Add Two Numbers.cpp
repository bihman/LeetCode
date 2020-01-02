/*
You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
*/

// v1.0
/**
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
        ListNode *p1, *p2, *r; 
        ListNode p(0);
        r = &p;
        int a,b,x = 0,value;
        p1 = l1;
        p2 = l2;
        while(p1 && p2)
        {
            a = p1->val;
            b = p2->val;
            value = (a + b + x) % 10;
            x = (a + b + x) / 10;
            r->next = new ListNode(value);     // 尾插法
            p1 = p1->next;
            p2 = p2->next;
            r = r->next;
        }
        
        while(p1)         // p1非空
        {
            a = p1->val;
            value = (a + x) % 10;
            x = (a + x) / 10;
            r->next = new ListNode(value);
            p1 = p1->next;
            r = r->next;
        }
        
        while(p2)        // p2非空
        {
            b = p2->val;
            value = (b + x) % 10;
            x = (b + x) / 10;
            r->next = new ListNode(value);
            p2 = p2->next;
            r = r->next;
        }
        
        if(x > 0)        // 此时x应为1
        {
            r->next = new ListNode(x);
        }
        
        return p.next;
    }
  };
