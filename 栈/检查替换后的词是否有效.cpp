class Solution {
public:
    //�����ַ���������ab����ջ������c���ж�ջ����Ԫ���뵱ǰ��c�ܷ����abc
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
        //����δƥ��c�Ĵ������ش���
        if (stk.empty())
            return true;
        return false;
    }
};