/*
Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.
*/


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
    ListNode* deleteDuplicates(ListNode* head) 
    {
      if(head == NULL)
        return NULL;
      ListNode *p = head,*q = p->next;
      ListNode List(-1), *r = &List;
      int value;
      while(q)
      {
        if(p->val == q->val)
        {
          p = q;
          q = p->next;
        }
        else
        {
          val = p->val;
          r->next = new ListNode(value);
          p = q;
          q = p->next;
          r = r->next;
        }
      }
      if(p)
        r->next = new ListNode(p->val);
      return List.next;
    }
};
