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
    //转换为数组的插入排序
    ListNode* insertionSortList(ListNode* head) {
        ListNode* p = head;
        vector<int> v;
        while (p)
        {
            v.push_back(p->val);
            p = p->next;
        }
        int n = v.size();
        for (int i = 1;i < n;i++)
        {
            int j = i - 1;
            int key = v[i];
            while (j >= 0 && key < v[j])
            {
                v[j + 1] = v[j];
                j--;
            }
            v[j + 1] = key;
        }
        ListNode* first = new ListNode;
        p = first;
        for (int i = 0;i < n;i++)
        {
            p->next = new ListNode(v[i]);
            p = p->next;
        }
        return first->next;
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
    ListNode* insertionSortList(ListNode* head) {
        if (head == NULL)
            return NULL;
        ListNode* first = new ListNode(-1, head);
        ListNode* p = head->next, * tail = head;        //p指向未排序的第一个元素，tail指向排好序的最后一个元素
        while (p)
        {
            if (p->val < tail->val)
            {
                ListNode* curr = first;         //找到要插入p的位置
                while (p->val > curr->next->val)
                {
                    curr = curr->next;
                }
                //循环结束时curr指向p要插入的位置之前
                tail->next = p->next;   //记住下一次未排序的第一个元素
                p->next = curr->next;   //  A->C插入B  有B->next=C
                curr->next = p;         //A->next=B
                p = tail->next;         //更新未排序的第一个元素
            }
            else
            {
                p = p->next;
                tail = tail->next;
            }
        }
        return first->next;
    }
};