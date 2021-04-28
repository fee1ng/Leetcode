class MinStack {
public:
    /** initialize your data structure here. */
    //需要一个辅助栈和一个数据栈，辅助栈记载当前数据栈对应位置的最小元素
    stack<int> s1, s2;
    MinStack() {
        while (!s1.empty())
        {
            s1.pop();
        }
        while (!s2.empty())
        {
            s2.pop();
        }
    }

    void push(int x) {
        s1.push(x);
        if (s2.empty() || s2.top() > x)
            s2.push(x);
        else
            s2.push(s2.top());
    }

    void pop() {
        s1.pop();
        s2.pop();
    }

    int top() {
        return s1.top();

    }

    int min() {
        return s2.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */