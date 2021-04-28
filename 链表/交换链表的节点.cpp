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
    ListNode* swapNodes(ListNode* head, int k) {
        int num = 0;
        ListNode* fast = head, * slow = head;
        ListNode* tmp = nullptr;
        //ǰ��k-1��
        for (int i = 0;i < k - 1;i++)
        {
            fast = fast->next;
        }
        tmp = fast;
        while (fast->next)
        {
            fast = fast->next;
            slow = slow->next;
        }
        //slowΪ������k���ڵ�
        swap(slow->val, tmp->val);
        return head;
    }
};