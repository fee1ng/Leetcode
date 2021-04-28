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
    //����������temp����������ڵ�,temp��ֵΪ�ƽڵ�
    ListNode* swapPairs(ListNode* head) {
        ListNode* first = new ListNode(-1);
        first->next = head;
        ListNode* temp = first;
        while (temp->next && temp->next->next)
        {
            ListNode* a = temp->next;
            ListNode* b = temp->next->next;
            temp->next = b;
            a->next = b->next;
            b->next = a;
            temp = a;
        }
        return first->next;
    }
};

//��ջ�洢���������Ľڵ磬������������������Ϊ�������������һ���ڵ���������

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        stack<ListNode*> s;
        ListNode* p = new ListNode(-1);
        ListNode* curr = head;
        head = p;       //�洢�������ͷ�ڵ�
        while (curr && curr->next)
        {
            s.push(curr);
            s.push(curr->next);
            curr = curr->next->next;
            p->next = s.top();
            s.pop();
            p = p->next;
            p->next = s.top();
            s.pop();
            p = p->next;
        }
        if (curr != nullptr)    //�������������ڵ�
            p->next = curr;
        else
            p->next = nullptr;
        return head->next;
    }
};
