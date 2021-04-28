class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> v;
        ListNode* p = head;
        while (p)
        {
            v.push_back(p->val);
            p = p->next;
        }
        for (int i = 0, j = v.size() - 1;i < j;i++, j--)
        {
            if (v[i] != v[j])
                return false;
        }
        return true;
    }
};




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
    //快慢指针找到中间节点
    //反转后半部分节点与前面的节点比较
    bool isPalindrome(ListNode* head) {
        ListNode* first = new ListNode;
        first->next = head;
        ListNode* slow = first, * fast = first;
        while (fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* q = re(slow->next);
        while (head && q)
        {
            if (head->val != q->val)
                return false;
            head = head->next;
            q = q->next;
        }
        return true;
    }
    //迭代反转链表
    ListNode* re(ListNode* p)
    {
        ListNode* newNode = nullptr;
        while (p)
        {
            ListNode* next = p->next;
            p->next = newNode;
            newNode = p;
            p = next;
        }
        return newNode;
    }

};