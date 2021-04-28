/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    //A->B->C->D   深拷贝为
    //A'->B'->C'->D'
    //用哈希表m建立pair<A,A'> <B,B'>
    //A->random=D,则A'->random=D'，即m[A]->random=m[D]=m[A->random]
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> m;
        Node* first = new Node(-1);
        Node* p = head;
        Node* curr = first;
        while (p)
        {
            curr->next = new Node(p->val);
            m[p] = curr->next;
            curr = curr->next;
            p = p->next;
        }
        p = head, curr = first;
        while (p)
        {
            curr->next->random = m[p->random];
            curr = curr->next;
            p = p->next;
        }
        return first->next;
    }
};


/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    //A->B->C->D
    //A->A'->B->B'->C->C'->D->D'
    //A'->random=A->random->next  ==>   A->next->random=A->random->next
    Node* copyRandomList(Node* head) {
        if (head == nullptr)
            return nullptr;
        Node* p = head;
        //构造A->A'->B->B'->C->C'->D->D'
        while (p)
        {
            Node* curr = new Node(p->val);
            curr->next = p->next;
            p->next = curr;
            curr->random = nullptr;
            p = curr->next;
        }
        //根据A'->random=A->random->next完成新链表的random赋值
        p = head;
        while (p)
        {
            if (p->random)
                p->next->random = p->random->next;
            else
                p->next->random = nullptr;
            p = p->next->next;
        }
        //将一个链表拆分成两个链表
        /*Node* preNode = head;
        Node* first = preNode->next;
        while (preNode)
        {
            p = preNode->next;
            preNode->next = p->next;
            preNode = preNode->next;
            if (preNode != nullptr)
                p->next = preNode->next;
            else
                p->next = nullptr;
        }
        return first;*/
        p = head;       //p=A
        Node* first = new Node(-1);
        Node* tmp = first;
        while (p)
        {
            first->next = p->next;  //first->next=A'
            p->next = first->next->next;    //A->next=B
            p = p->next;        //p=B
            first = first->next;    //first=A'
        }
        return tmp->next;
    }
};