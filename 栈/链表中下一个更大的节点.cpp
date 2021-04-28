/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//µ¥µ÷Õ»
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        ListNode* p = head;
        if (head->next == nullptr)
            return { 0 };

        int len = getLen(p);
        vector<int> res(len);
        vector<int> v;
        p = head;

        while (p)
        {
            v.push_back(p->val);
            p = p->next;
        }
        stack<int> s;

        int i = 0;
        while (i < len)
        {
            if (s.empty() || v[s.top()] >= v[i])
                s.push(i++);
            else
            {
                res[s.top()] = v[i];
                s.pop();
            }
        }
        return res;
    }
    int getLen(ListNode* head)
    {
        int len = 0;
        while (head)
        {
            len++;
            head = head->next;
        }
        return len;
    }
};