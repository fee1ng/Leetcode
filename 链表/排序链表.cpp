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
    //�鲢����
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode* slow = head, * fast = head->next;
        /*����ָ������е㽫����ֳ�����*/
        while (fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* right = slow->next;     //������
        slow->next = nullptr;             //����
        ListNode* p = sortList(head);
        ListNode* q = sortList(right);
        return merge(p, q);      //�ϲ�
    }
    ListNode* merge(ListNode* p, ListNode* q)
    {
        ListNode* first = new ListNode(-1);
        ListNode* curr = first;
        while (p && q)
        {
            if (p->val < q->val)
            {
                curr->next = new ListNode(p->val);
                curr = curr->next;
                p = p->next;
            }
            else
            {
                curr->next = new ListNode(q->val);
                curr = curr->next;
                q = q->next;
            }
        }
        while (p)
        {
            curr->next = new ListNode(p->val);
            curr = curr->next;
            p = p->next;
        }
        while (q)
        {
            curr->next = new ListNode(q->val);
            curr = curr->next;
            q = q->next;
        }
        return first->next;
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
    //�֣�
    //��һ����Ϊ��ǰָ���λ��
    //�ڶ�����Ϊ��ǰָ��λ��step���ȵ�ָ��λ��
    //��������ʣ�²��ֵ�ͷָ��
    //��:
    //�����������ֺ�����
    //��֮ǰ�Ѿ��ź��������ͺ������ⲿ��һ�������(preָ���Ѿ��ź���������βָ��)
    //ѭ���� ��ֱ������ȫ��������
    //����step�ĳ���,��1 2 4...... length-1
    ListNode* sortList(ListNode* head) {
        ListNode* dummy = new ListNode(-1, head);
        int length = GetLength(head);
        for (int step = 1;step < length;step = step * 2)
        {
            ListNode* pre = dummy;
            ListNode* curr = dummy->next;
            //��
            while (curr != nullptr)
            {
                ListNode* A = curr;   //��һ����
                ListNode* B = cut(A, step);    //�ڶ�����
                curr = cut(B, step);   //��Ϊ���зֲ��ֵ�����ͷָ��
                //�Σ��ϲ���һ���ֺ͵ڶ�����
                ListNode* temp = merge(A, B);
                //�����Ѿ��ź���Ĳ��ֺ͸ո��ź���Ĳ���
                pre->next = temp;
                //�����Ѿ��ź��򲿷ֵ�βָ��
                while (pre->next)
                {
                    pre = pre->next;
                }
            }
        }
        return dummy->next;
    }
    int GetLength(ListNode* head)
    {
        int L = 0;
        while (head)
        {
            L++;
            head = head->next;
        }
        return L;
    }
    //�и�������ָ��head��ʼ(����head����)step������������������жϣ������غ��������ͷָ��
    ListNode* cut(ListNode* head, int step)
    {
        if (head == nullptr)
            return nullptr;
        ListNode* curr = head;
        for (int i = 1;i < step && curr->next != nullptr;i++)
        {
            curr = curr->next;
        }
        ListNode* rightHead = curr->next;
        curr->next = nullptr;     //����
        return rightHead;
    }
    //�ϲ���������������
    ListNode* merge(ListNode* p, ListNode* q)
    {
        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;
        while (p && q)
        {
            if (p->val < q->val)
            {
                curr->next = new ListNode(p->val);
                p = p->next;
            }
            else
            {
                curr->next = new ListNode(q->val);
                q = q->next;
            }
            curr = curr->next;
        }
        while (p)
        {
            curr->next = new ListNode(p->val);
            curr = curr->next;
            p = p->next;
        }
        while (q)
        {
            curr->next = new ListNode(q->val);
            curr = curr->next;
            q = q->next;
        }
        return dummy->next;
    }
};