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
    //找到倒数第k个节点，然后将其后面部分与前半部分相接
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || k == 0)
            return head;
        int L = GetLength(head);
        int n = k % L;
        if (n == 0)    //如果n=0,即k=L,旋转L次又回到原链表，没有修改的必要
            return head;
        ListNode* curr = kthLast(head, n);     //找到倒数第k个节点
        ListNode* dummy = new ListNode(-1, curr);
        ListNode* p = head;
        //将倒数第k个节点之前的链表进行断链
        while (p->next != curr)
        {
            p = p->next;
        }
        p->next = nullptr;
        //找到倒数第k个节点后的最后一个节点与头节点相连
        while (curr && curr->next)
        {
            curr = curr->next;
        }
        curr->next = head;
        return dummy->next;
    }
    int GetLength(ListNode* head)
    {
        int L = 0;
        while (head)
        {
            L++;
            head = head->next;
        }
        return L;
    }
    ListNode* kthLast(ListNode* head, int k)
    {
        if (k == 0)
            return head;
        ListNode* dummy = new ListNode(-1, head);
        ListNode* fast = dummy, * slow = dummy;
        int n = 0;
        while (n <= k)
        {
            fast = fast->next;
            n++;
        }
        while (fast)
        {
            fast = fast->next;
            slow = slow->next;
        }
        return slow->next;
    }
};