/*
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.
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
      ListNode List(-1), *r = &List;
      ListNode *p = head, *q = p->next;
      int count = 1;   // count用于记p所指结点的个数
      int value;
      while(q)
      {
        if(p->val == q->val)
        {
          count++;
          p = q;
          q = p->next;
        }
        else if(p->val != q->val && count == 1)
        {
          value = p->val;
          r->next = new ListNode(value);
          p = q;
          q = p->next;
          r = r->next;
          count = 1;
        }
        else
        {
          p = q;
          q = p->next;
          count = 1;
        }
      }
      if(count == 1)
        r->next = new ListNode(p->val);
      return List.next;
    }
};
