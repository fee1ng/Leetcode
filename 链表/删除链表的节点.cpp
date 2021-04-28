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
    //O(1)
    //�ҵ�Ҫ��ɾ���Ľڵ㣬���ýڵ�����ֵ����ýڵ㲢�޸�next
    //�������1��Ҫɾ���Ľڵ�Ϊβ�ڵ�
    //���2��Ҫɾ���Ľڵ㼴Ϊͷ�ڵ�Ҳ��β�ڵ�
    //����β�ڵ�ʱ����Ҫ��ͷ������β�ڵ�֮ǰ���Ǹ��ڵ�
    //�������2����������һ��ͷ�ڵ�ͳһ���1��2����ʱҪɾ���Ľڵ�ز����ܼ���ͷ�ڵ�Ҳ��β�ڵ�
    ListNode* deleteNode(ListNode* head, int val) {
        ListNode* first = new ListNode(-1);
        first->next = head;
        ListNode* p = head;
        while (p)
        {
            if (p->val == val)
            {
                if (p->next == nullptr)
                {
                    ListNode* q = first;
                    while (q && q->next->val != val)
                    {
                        q = q->next;
                    }
                    q->next = nullptr;
                }
                else
                {
                    p->val = p->next->val;
                    p->next = p->next->next;
                }
            }
            p = p->next;
        }
        return first->next;
    }
};


class Solution {
public:
    //�ҵ�Ҫɾ���ڵ�֮ǰ���Ǹ�ָ�룬����nextֵ
    ListNode* deleteNode(ListNode* head, int val) {
        ListNode* first = new ListNode(-1);
        ListNode* p = first;
        first->next = head;
        while (p && p->next)
        {
            if (p->next->val == val)
            {
                p->next = p->next->next;
            }
            p = p->next;
        }
        return first->next;
    }
};