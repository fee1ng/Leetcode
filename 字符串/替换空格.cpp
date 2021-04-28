class Solution {
public:
    //新建空间，不在原字符串中修改。
    string replaceSpace(string s) {
        string res;
        string tmp;
        for (auto c : s)
        {
            if (c != ' ')
                tmp += c;
            if (c == ' ')
            {
                tmp += "%20";
                res += tmp;
                tmp = "";
            }
        }
        res += tmp;
        return res;
    }
};

class Solution {
public:
    //不新建空间，在原字符串上修改
    string replaceSpace(string s) {
        int L = s.size();
        int space = 0;    //统计有几个空格
        //第一次遍历统计有几个空格，更新修改后的字符串的长度
        //一个空格长度+2
        for (auto c : s)
        {
            if (c == ' ')
                space++;
        }

        int realL = L + 2 * space;
        s.resize(realL);

        //两个指针，一个指向新字符串的末尾，一个指向原来字符串的末尾
        int j = realL - 1, i = L - 1;
        while (i >= 0)
        {
            //不是空格，则复制
            if (s[i] != ' ')
            {
                s[j] = s[i];
                j--;
                i--;
            }
            //是空格，则替换
            else if (s[i] == ' ')
            {
                s[j--] = '0';
                s[j--] = '2';
                s[j--] = '%';
                i--;
            }
        }
        return s;
    }
};