class Solution {
public:
    //遍历字符串，遇到ab则入栈，遇到c则判断栈顶两元素与当前的c能否组成abc
    bool isValid(string s) {
        stack<char> stk;
        for (auto& c : s)
        {
            if (c == 'a' || c == 'b')
                stk.push(c);
            else
            {
                if (stk.size() < 2)
                    return false;
                else
                {
                    if (stk.top() == 'b')
                        stk.pop();
                    else
                        return false;
                    if (stk.top() == 'a')
                        stk.pop();
                    else
                        return false;
                }
            }
        }
        //还有未匹配c的串，返回错误
        if (stk.empty())
            return true;
        return false;
    }
};