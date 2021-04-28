class LRUCache {

public:
    struct ListNode
    {
        ListNode* pre;
        ListNode* next;
        int key;
        int val;
        ListNode() : key(0), val(0), pre(nullptr), next(nullptr) {}
        ListNode(int k, int v) : key(k), val(v), pre(nullptr), next(nullptr) {}
    };
    unordered_map<int, ListNode*> hash;
    ListNode* head;
    ListNode* tail;
    int capacity;
    int size;
    LRUCache(int _capacity) {
        capacity = _capacity;
        head = new ListNode;
        tail = new ListNode;
        head->next = tail;
        tail->pre = head;
        size = 0;
    }
    void moveToHead(ListNode* curr)
    {
        curr->pre->next = curr->next;
        curr->next->pre = curr->pre;

        curr->pre = head;
        curr->next = head->next;
        head->next->pre = curr;
        head->next = curr;
    }
    int get(int key) {
        if (!hash.count(key))
            return -1;
        //move to head
        ListNode* curr = hash[key];
        moveToHead(curr);
        return curr->val;
    }

    void put(int key, int value)
    {
        if (hash.count(key))
        {
            ListNode* curr = hash[key];
            curr->val = value;
            moveToHead(curr);
        }
        else
        {
            ListNode* newNode = new ListNode(key, value);
            hash[key] = newNode;
            size++;
            addToHead(newNode);
            if (size > capacity)
            {
                ListNode* removeNode = tail->pre;
                removeNode->pre->next = removeNode->next;
                removeNode->next->pre = removeNode->pre;
                hash.erase(removeNode->key);
                delete removeNode;
                size--;
            }
        }
    }
    void addToHead(ListNode* newNode)
    {
        newNode->pre = head;
        newNode->next = head->next;
        head->next->pre = newNode;
        head->next = newNode;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */