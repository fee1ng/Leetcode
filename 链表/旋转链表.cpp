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
    //�ҵ�������k���ڵ㣬Ȼ������沿����ǰ�벿�����
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || k == 0)
            return head;
        int L = GetLength(head);
        int n = k % L;
        if (n == 0)    //���n=0,��k=L,��תL���ֻص�ԭ����û���޸ĵı�Ҫ
            return head;
        ListNode* curr = kthLast(head, n);     //�ҵ�������k���ڵ�
        ListNode* dummy = new ListNode(-1, curr);
        ListNode* p = head;
        //��������k���ڵ�֮ǰ��������ж���
        while (p->next != curr)
        {
            p = p->next;
        }
        p->next = nullptr;
        //�ҵ�������k���ڵ������һ���ڵ���ͷ�ڵ�����
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