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
    //归并排序
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode* slow = head, * fast = head->next;
        /*快慢指针查找中点将链表分成两半*/
        while (fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* right = slow->next;     //右链表
        slow->next = nullptr;             //断链
        ListNode* p = sortList(head);
        ListNode* q = sortList(right);
        return merge(p, q);      //合并
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
    //分：
    //第一部分为当前指针的位置
    //第二部分为当前指针位置step长度的指针位置
    //保存链表剩下部分的头指针
    //治:
    //把上述两部分合起来
    //把之前已经排好序的链表和合起来这部分一起合起来(pre指向已经排好序的链表的尾指针)
    //循环分 治直到链表被全部分治完
    //更换step的长度,从1 2 4...... length-1
    ListNode* sortList(ListNode* head) {
        ListNode* dummy = new ListNode(-1, head);
        int length = GetLength(head);
        for (int step = 1;step < length;step = step * 2)
        {
            ListNode* pre = dummy;
            ListNode* curr = dummy->next;
            //分
            while (curr != nullptr)
            {
                ListNode* A = curr;   //第一部分
                ListNode* B = cut(A, step);    //第二部分
                curr = cut(B, step);   //还为进行分部分的链表头指针
                //治，合并第一部分和第二部分
                ListNode* temp = merge(A, B);
                //连接已经排好序的部分和刚刚排好序的部分
                pre->next = temp;
                //更新已经排好序部分的尾指针
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
    //切割链表，从指针head开始(包括head本身)step步的链表与后续链表切断，并返回后续链表的头指针
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
        curr->next = nullptr;     //断链
        return rightHead;
    }
    //合并两个链有序链表
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