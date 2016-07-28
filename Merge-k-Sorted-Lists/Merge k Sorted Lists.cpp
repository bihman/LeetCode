/*
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
*/

// 思路：不断的进行两个有序链表的合并

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
    ListNode l3(-1), *p1 = l1, *p2 = l2, *r = &l3;
    int value;
    while(p1 && p2)
    {
      if(p1->val < p2->val)
      {
        value = p1->val;
        r->next = new ListNode(value);
        p1 = p1->next;
        r = r->next;
      }
      else
      {
        value = p2->val;
        r->next = new ListNode(value);
        p2 = p2->val;
        r = r->next;
      }
    }
    while(p1)
    {
      value = p1->val;
      r->next = new ListNode(value);
      p1 = p1->next;
      r = r->next;
    }
    while(p2)
    {
      value = p2->val;
      r->next = new ListNode(value);
      p2 = p2->val;
      r = r->next;
    }
    return l3.next;
  }
  ListNode *mergeKLists(vector<ListNode *>& lists)
  {
    ListNode *p;
    if(lists.size() == 0)
      return NULL;
    p = lists[0];
    int i;
    for(i = 1; i < lists.size(); i++)
      p = mergeTwoLists(p, lists[i]);
    return p;
  }
};      //  该方法超时(TLE)了......

class Solution
{
public:
  ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
  {
    ListNode *l3,*r;
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
    r = l3;    // 采用尾插法
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
  ListNode *mergeKLists(vector<ListNode *>& lists)
  {
    ListNode *p;
    if(lists.size() == 0)
      return NULL;
    p = lists[0];
    int i;
    for(i = 1; i < lists.size(); i++)
      p = mergeTwoLists(p, lists[i]);
    return p;
  }
}:       // 该方法虽成功AC,但时间效率仍不高！！！
