class CQueue {
public:
    //s1ֻ��עpush���ݣ�s2pop����
    //ע��ֻ�е�s2Ϊ��ʱ���Ž�s1������push��s2
    stack<int> s1, s2;
    CQueue() {
        while (!s1.empty())
            s1.pop();
        while (!s2.empty())
            s2.pop();
    }

    void appendTail(int value) {
        s1.push(value);


    }

    int deleteHead() {
        if (s2.empty())
        {
            while (!s1.empty())
            {
                int curr = s1.top();
                s1.pop();
                s2.push(curr);
            }
        }
        if (s2.empty())
            return -1;
        int res = s2.top();
        s2.pop();
        return res;
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */