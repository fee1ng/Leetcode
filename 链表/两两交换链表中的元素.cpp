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
    //迭代，交换temp后面的两个节点,temp初值为哑节点
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

//用栈存储两个连续的节电，并交换，如果链表个数为奇数个，则将最后一个节点加入链表后方

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        stack<ListNode*> s;
        ListNode* p = new ListNode(-1);
        ListNode* curr = head;
        head = p;       //存储新链表的头节点
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
        if (curr != nullptr)    //链表有奇数个节点
            p->next = curr;
        else
            p->next = nullptr;
        return head->next;
    }
};
