class Solution {
public:
    //ȥ�ո񣬴��ڿ�ס���ʣ���ջ����
    string reverseWords(string s) {
        int n = s.size();
        if (n == 0)
            return "";
        int i = 0, j = n - 1;
        while (s[i] == ' ')
            i++;
        if (i == n)
            return "";
        while (s[j] == ' ')
            j--;
        s = s.substr(i, j - i + 1);
        i = 0, n = s.size();
        j = 0;
        string tmp;
        stack<string> stk;
        while (j < n)
        {
            if (s[j] == ' ')
            {
                if (s[i] != ' ')
                {
                    stk.push(tmp);
                    tmp.clear();
                    i = j + 1;
                }
                else {
                    //j++;
                    i++;
                }
            }
            else
            {
                tmp += s[j];
            }
            j++;
        }
        stk.push(tmp);
        string res;
        while (!stk.empty())
        {
            string str = stk.top();
            stk.pop();
            res = res + str + ' ';
        }
        if (res.size() == 0)
            return "";
        res = res.substr(0, res.size() - 1);
        return res;
    }
};





class Solution {
public:
    //ȥ�ո񣬴��ڿ�ס���ʷ�ת
    string reverseWords(string s) {
        int n = s.size();
        if (n == 0)
            return "";
        int i = 0, j = n - 1;
        while (s[i] == ' ')
            i++;
        if (i == n)
            return "";
        while (s[j] == ' ')
            j--;

        string word;
        stack<string> stk;
        while (i <= j)
        {
            if (s[i] == ' ' && word.size())
            {
                stk.push(word);
                word = "";
            }
            else if (s[i] != ' ')
                word += s[i];
            i++;
        }
        stk.push(word);
        string res;
        while (!stk.empty())
        {
            string tmp = stk.top();
            stk.pop();
            res = res + tmp + ' ';
        }
        res = res.substr(0, res.size() - 1);
        return res;
    }
};