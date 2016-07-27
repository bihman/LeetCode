/*
Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:
Given n will always be valid.
Try to do this in one pass.
*/

// 该链表的head为第一个结点
// 解法一： 一般解法

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
  ListNode *removeNthFromEnd(ListNode *head, int n)
  {
    ListNode *p = head, *q;
    int count = 0, i;
    while(p != NULL)  // 统计链表的长度
    {
      count++;
      p = p->next;
    }
    if(count == n)    // 当要删除的结点为链表的第一个结点时
    {
      p = head;
      head = head->next;
      delete p;
      return head;
    }
    else
    {
      p = head;
      for(i = 1; i < count-n; i++)   // p为倒数第n个结点的前一个结点
      {
        p = p->next;
      }
      q = p->next;
      p->next = q->next;
      delete q;
      return head;
    }
  }
};



// 解法二：采用两个指针p和q，先让p走n步，然后再让p和q一起走，当p走到链表尾时，q的下一个结点即为要删除的结点

class Solution
{
public:
  ListNode *removeNthFromEnd(ListNode *head, int n)
  {
    ListNode *p = head, *q = head, *r;
    int i;
    for(i = 1; i <= n; i++)   // 让p先走n步
    {
      p = p->next;
    }
    if(p == NULL) // 链表仅有一个结点或要删除的结点为第一个结点
      return head->next;
    while(p != NULL && p->next != NULL)  // p和q同时走
    {
      p = p->next;
      q = q->next;
    }
    r = q->next;
    if(r != NULL)
      q->next = r->next;
    return head;
  }
};
