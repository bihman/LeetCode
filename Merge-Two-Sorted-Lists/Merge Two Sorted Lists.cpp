/*
Merge two sorted linked lists and return it as a new list. 
The new list should be made by splicing together the nodes of the first two lists.
*/

// 合并两个有序表
// 思路：逐个元素进行比较
// 解法一：

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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
      ListNode p(-1);   // 创建一个新的链表p
      ListNode *p1 = l1, *p2 = l2, *r = &p;  // r始终指向p的尾结点，采用尾插法插入元素
      int value;
      while(p1 && p2)  // 当p1和p2均不为空时
      {
        if(p1->val < p2->val)  // 将p1所指向的元素插入新的链表中
        {
          value = p1->val;
          r->next = new ListNode(value);   // 尾插法
          p1 = p1->next;
          r = r->next;
        }
        else                  // 将p2所指向的元素插入新的链表中
        {
          value = p2->val;
          r->next = new ListNode(value);
          p2 = p2->val;
          r = r->next;
        }
      }
      
      while(p1)   // 当p1不为空时
      {
        value = p1->val;
        r->next = new ListNode(value);
        p1 = p1->next;
        r = r->next;
      }
      
      while(p2)   // 当p2不为空时
      {
        value = p2->val;
        r->next = new ListNode(value);
        p2 = p2->next;
        r = r->next;
      }
      
      return p.next;
    }
 };


// 解法二：
class Solution
{
public:
 ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
 {
  ListNode *l3, *p;
  if(l1 == NULL)
   return l2;
  if(l2 == NULL)
   return l1;
  if(l1->val < l2->val)
  {
   l3 = l1;
   l1 = l1->next;
  }
  else
  {
   l3 = l2;
   l2 = l2->next;
  }
  p = l3;
  while(l1 && l2)
  {
   if(l1->val < l2->val)
   {
    p->next = l1;
    p = p->next;
    l1 = l1->next;
   }
   else
   {
    p->next = l2;
    p = p->next;
    l2 = l2->next;
   }
  }
  if(l1)
   p->next = l1;
  else
   p->next = l2;
  return l3;
 }
};
