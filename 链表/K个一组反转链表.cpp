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
//注意后半部分链表反转后需要将已经反转的链表尾连上刚反转的链表头
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k == 1)
            return head;
        ListNode* pre = nullptr;
        ListNode* tail = nullptr;
        ListNode* curr = head;
        ListNode* res = nullptr;
        ListNode* first = head;
        int n = 0;
        int flag = 0;
        while (curr)
        {
            curr = curr->next;
            n++;
            if (n == k - 1 && flag == 0)
            {
                res = curr;
                flag++;
            }
            if (n == k)
            {
                auto temp = help(first, curr);
                tail = temp.second;
                if (pre)
                    pre->next = tail;
                pre = temp.first;

                n = 0;
                first = curr;
            }
        }
        return res;
    }
    pair<ListNode*, ListNode*> help(ListNode* head, ListNode* tail)
    {
        ListNode* curr = head;
        ListNode* pre = nullptr;
        while (curr != tail)
        {
            ListNode* tmp = curr->next;
            curr->next = pre;
            pre = curr;
            curr = tmp;
        }
        head->next = tail;
        return { head,pre };
    }
};