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
    //找到要被删除的节点，将该节点后面的值替代该节点并修改next
    //考虑情况1：要删除的节点为尾节点
    //情况2：要删除的节点即为头节点也是尾节点
    //遇到尾节点时，需要从头遍历到尾节点之前的那个节点
    //考虑情况2，则需增加一个头节点统一情况1，2，此时要删除的节点必不可能既是头节点也是尾节点
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
    //找到要删除节点之前的那个指针，设置next值
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