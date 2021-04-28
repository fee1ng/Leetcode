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
    //让一个指针先行前进n+1步则快慢指针相距n
    //生成头节点，使得前进不会越界 即n=链表长度。
    //快指针比慢指针快n部，则快指针到末尾时慢指针恰好在倒数第n个节点
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