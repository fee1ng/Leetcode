/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;
        ListNode* res = fast;
        ListNode* slow = head;
        int count = 0;
        while (slow)
        {
            count++;
            slow = slow->next;
        }
        int i = 1;
        while (i < count - n)
        {
            fast = fast->next;
            i++;
        }
        if (count == n)
            return head->next;
        if (fast->next)
            fast->next = fast->next->next;
        return res;
    }
};


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    //��һ��ָ������ǰ��n+1�������ָ�����n
    //����ͷ�ڵ㣬ʹ��ǰ������Խ�� ��n=�����ȡ�
    //��ָ�����ָ���n�������ָ�뵽ĩβʱ��ָ��ǡ���ڵ�����n���ڵ�
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* newHead = new ListNode(-1, head);
        ListNode* slow = newHead, * fast = newHead;
        int i = 1;
        while (i <= n + 1)
        {
            fast = fast->next;
            i++;
        }
        while (fast)
        {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return newHead->next;
    }
};