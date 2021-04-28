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
    //ת��Ϊ����Ĳ�������
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
        ListNode* p = head->next, * tail = head;        //pָ��δ����ĵ�һ��Ԫ�أ�tailָ���ź�������һ��Ԫ��
        while (p)
        {
            if (p->val < tail->val)
            {
                ListNode* curr = first;         //�ҵ�Ҫ����p��λ��
                while (p->val > curr->next->val)
                {
                    curr = curr->next;
                }
                //ѭ������ʱcurrָ��pҪ�����λ��֮ǰ
                tail->next = p->next;   //��ס��һ��δ����ĵ�һ��Ԫ��
                p->next = curr->next;   //  A->C����B  ��B->next=C
                curr->next = p;         //A->next=B
                p = tail->next;         //����δ����ĵ�һ��Ԫ��
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