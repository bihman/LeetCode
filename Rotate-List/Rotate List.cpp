/*
Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.
*/

/**
 * 思路：
 * 1. 只要是和链表有关，第一步需要判断head是否为NULL;
 * 2. k == 0 时，返回链表本身
 * 3. k有可能大于链表的长度，当k大于链表长度时，重新回到起始位置计数，于是k = k % len; (len为链表的长度)
 * 4. 本题我们将链表构成一个循环链表，当p(开始时为p = head)走到链表尾时，此时将p->next = head构成一个环，然后在此基础上
 * 再向前走k步，即为所要旋转位置的前一个元素，此时将链表头赋为该元素的下一个结点，然后将链表从该元素处断开，即为所求。
 * /

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
    ListNode *rotateRight(ListNode *head, int k)
    {
        if(head == NULL || k == 0)
            return head;
        ListNode *p = head;
        int len = 1;
        while(p->next)
        {
            len++;
            p = p->next;
        }
        k = k % len;
        if(k == 0)
            return head;
        p->next = head;   // 构成一个环
        k = len - k;
        int i;
        for(i = 1; i <= k; i++)
            p = p->next;
        head = p->next;
        p->next = NULL;
        return head;
    }
};
