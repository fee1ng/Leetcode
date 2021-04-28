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
    //寻找链表中点 + 链表逆序 + 合并链表
    //栈存储节点，一个前面遍历的节点对应一个后面的节点，只须对应一半链表的长度
    void reorderList(ListNode* head) {
        if (head == nullptr)
            return;
        stack<ListNode*> s;
        ListNode* p = head;
        int count = 1;
        while (p)
        {
            s.push(p);
            p = p->next;
            count++;
        }
        count--;
        int n = 1;
        p = head;
        ListNode* tmp, * curr;
        while (p && n <= count / 2)
        {
            tmp = p->next;
            curr = s.top();
            s.pop();
            p->next = curr;
            curr->next = tmp;
            p = curr->next;
            n++;
        }
        if (s.size() == count / 2)
            p->next = nullptr;
        else
        {
            p->next = s.top();
            p->next->next = nullptr;
        }
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
    //线性表支持随机访问
    void reorderList(ListNode* head) {
        if (head == nullptr)
            return;
        vector<ListNode*> v;
        ListNode* p = head;
        while (p)
        {
            v.push_back(p);
            p = p->next;
        }
        int i = 0, j = v.size() - 1;
        p = head;
        while (i < j)
        {
            p = v[i];     //原链表的前半部分L0 L1........
            i++;
            p->next = v[j];   //原链表的后半部分Ln,Ln-1...........
            j--;
            p = p->next;      //L0->next=Ln
            p->next = v[i];   //Ln->next=L1
            p = p->next;      //p=L1
        }
        p->next = nullptr;
    }
};