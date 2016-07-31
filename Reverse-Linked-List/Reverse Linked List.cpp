/*
Reverse a singly linked list.
*/

// 没有难度，采用头插法插入元素

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
    ListNode* reverseList(ListNode* head) 
    {
      if(head == NULL)
        return NULL;
      ListNode List(-1), *r = &List;
      ListNode *p = head, *q;
      while(p)
      {
        q = p->next;
        p->next = r->next;
        r->next = p;
        p = q;
      }
      return List.next;
    }
};
