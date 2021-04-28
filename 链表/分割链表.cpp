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
    //�ȸ���Ԫ��ֵ�Ĵ�С��ֳ�������������������
    ListNode* partition(ListNode* head, int x) {
        ListNode* less = new ListNode;
        ListNode* great = new ListNode;
        ListNode* tmp = great;
        ListNode* p = head;
        head = less;
        while (p)
        {
            if (p->val < x)
            {
                less->next = new ListNode(p->val);
                less = less->next;
            }
            else
            {
                great->next = new ListNode(p->val);
                great = great->next;
            }
            p = p->next;
        }
        less->next = tmp->next;
        return head->next;
    }
};