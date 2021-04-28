class LFUCache {
public:
    //unordered_map<int,Node>+set<Node>保存最不经常使用的节点
    //重载<使得set容器的首元素为最不经常使用的节点
    struct Node
    {
        int key;
        int val;
        int useTime;
        int fre;
        Node() : key(0), val(0), useTime(0), fre(0) {}
        Node(int _key, int _val, int _useTime, int _fre) :
            key(_key), val(_val), useTime(_useTime), fre(_fre) {}
        bool operator<(const Node& node) const
        {
            if (this->fre == node.fre)
                return this->useTime < node.useTime;
            else
                return this->fre < node.fre;
        }

    };

    int capacity;
    unordered_map<int, Node> data;
    set<Node> table;
    int size;
    int time;
    LFUCache(int _capacity) {
        size = 0;
        time = 0;
        capacity = _capacity;
    }

    void del()
    {
        auto it = table.begin();
        data.erase(it->key);
        table.erase(it);
        size--;
    }
    int get(int key) {
        time++;
        if (capacity == 0) {
            return -1;
        }
        if (data.find(key) != data.end())
        {
            auto it = data.find(key);
            Node node = it->second;
            table.erase(node);
            node.fre++;
            node.useTime = time;
            data[key] = node;
            table.insert(node);
            return node.val;
        }
        return -1;
    }

    void put(int key, int value)
    {
        time++;
        if (capacity == 0) {
            return;
        }
        auto it = data.find(key);
        if (it == data.end())
        {
            size++;
            if (data.size() == capacity)
            {
                auto delNode = table.begin();
                data.erase(delNode->key);
                table.erase(delNode);
            }
            Node node(key, value, time, 1);
            data[key] = node;
            table.insert(node);
        }
        else
        {
            Node node = it->second;
            table.erase(node);
            node.val = value;
            node.fre++;
            node.useTime = time;
            data[key] = node;
            table.insert(node);
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */