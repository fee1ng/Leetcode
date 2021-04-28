class Solution {
public:
    //思路:中缀表达式转后缀表达式，然后运算，转换规则如下:
    //遇到操作数，则存入vector数组
    //符号栈空且遇到运算符，运算符入栈
    //遇到左括号，入栈
    //遇到右括号，执行出栈，并将出栈符号存入vector数组，直到弹出的是左括号(左括号不存入vector)
    //遇到的是+ - * /，弹出符号栈中所有优先级大于等于该运算符的栈顶元素，然后该运算符入栈(所有运算符都大于左括号)
    //把栈里的元素都弹出存入vector数组
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