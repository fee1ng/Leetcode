class Solution {
public:
    //˼·:��׺���ʽת��׺���ʽ��Ȼ�����㣬ת����������:
    //�����������������vector����
    //����ջ����������������������ջ
    //���������ţ���ջ
    //���������ţ�ִ�г�ջ��������ջ���Ŵ���vector���飬ֱ����������������(�����Ų�����vector)
    //��������+ - * /����������ջ���������ȼ����ڵ��ڸ��������ջ��Ԫ�أ�Ȼ����������ջ(���������������������)
    //��ջ���Ԫ�ض���������vector����
    int help(vector<string>& v)
    {
        int n = v.size();
        stack<int> stk;
        for (int i = 0;i < n;i++)
        {
            string curr = v[i];
            if (curr != "*" && curr != "/" && curr != "+" && curr != "-")
                stk.push(stoi(curr));
            else
            {
                int L = stk.top();
                stk.pop();
                int R = stk.top();
                stk.pop();
                int sum = 0;
                if (curr == "*")
                    sum = L * R;
                else if (curr == "/")
                    sum = R / L;
                else if (curr == "+")
                    sum = L + R;
                else if (curr == "-")
                    sum = R - L;
                stk.push(sum);
            }
        }
        int res = stk.top();
        return res;
    }
    int calculate(string s) {
        vector<string> v;
        stack<char> sign;
        int n = s.size();

        for (int i = 0;i < n;i++)
        {
            char c = s[i];
            if (c == ' ')
                continue;
            if (c >= '0' && c <= '9')
            {
                int num = s[i] - '0';
                int j = i + 1;
                for (;j < n;j++)
                {
                    if (s[j] >= '0' && s[j] <= '9')
                        num = num * 10 + (s[j] - '0');
                    else
                        break;
                }
                v.push_back(to_string(num));
                i = j - 1;
            }


            else
            {
                if (sign.empty())
                    sign.push(c);
                else
                {
                    if (c == '(')
                        sign.push(c);
                    else if (c == ')')
                    {
                        while (sign.top() != '(')
                        {
                            char curr = sign.top();
                            string tmp;
                            tmp.push_back(curr);
                            v.push_back(tmp);
                            sign.pop();
                        }
                        sign.pop();
                    }
                    else if (c == '*' || c == '/')
                    {
                        while (1)
                        {
                            if (sign.empty())
                                break;
                            char curr = sign.top();
                            if (curr == '*' || curr == '/')
                            {
                                sign.pop();
                                string tmp;
                                tmp.push_back(curr);
                                v.push_back(tmp);
                            }
                            else
                                break;
                        }
                        sign.push(c);
                    }
                    else if (c == '+' || c == '-')
                    {
                        while (1)
                        {
                            if (sign.empty())
                                break;
                            char curr = sign.top();
                            if (curr == '*' || curr == '/' || curr == '+' || curr == '-')
                            {
                                sign.pop();
                                string tmp;
                                tmp.push_back(curr);
                                v.push_back(tmp);
                            }
                            else
                                break;
                        }

                        sign.push(c);
                    }
                }
            }
        }
        while (!sign.empty())
        {
            char curr = sign.top();
            string tmp(1, curr);
            sign.pop();
            v.push_back(tmp);
        }
        return help(v);
    }
};