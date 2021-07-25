/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存机制
 */

// @lc code=start
class LRUCache {
public:
    struct ListNode
    {
        ListNode* next;
        ListNode* prev;
        int val;
        int key;
        ListNode() : val(0),next(nullptr),prev(nullptr) {};
        ListNode(int _val,int _key) : val(_val),key(_key),next(nullptr),prev(nullptr) {}
    };
    int size;
    int capacity;
    ListNode* dummy,*tail;
    unordered_map<int,ListNode*> hash;

    LRUCache(int _capacity) {
        capacity = _capacity;
        dummy = new ListNode;
        tail = new ListNode;
        dummy->next= tail;
        tail->prev = dummy;
        size = 0;
    }
    
    void moveToHead(ListNode* curr)
    {
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
        
        curr->prev = dummy;
        curr->next = dummy->next;
        dummy->next->prev = curr;
        dummy->next = curr;
    }
    int get(int key) {
        auto it = hash.find(key);
        if(it!=hash.end())
        {
            moveToHead(it.second);
            return it.second->val;
        }
        return -1;
    }
    
    void addTohead(ListNode* curr)
    {
        curr->prev = dummy;
        curr->next = dummy->next;
        dummy->next->prev = curr;
        dummy->next = curr;
    }

    void deleteLast()
    {
        tail->prev = tail->prev->prev;
        tail->prev->prev->next = tail;
        hash.erase(tail->prev);
        delete tail->prev;
    }
    
    void put(int key, int value) {
        auto it = hash.find(key);
        if(it==hash.end())
        {
            if(size < capacity)
            {
                size++;
                ListNode* curr = new ListNode(key,value);
                addTohead(curr);
            }
            else
            {
                deleteLast();
                ListNode* curr = new ListNode(key,value);
                addTohead(curr);
            }
        }
        else
        {
            auto curr = hash[key];
            curr->val = value;
            moveToHead(curr);
        }
    }
};


/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

