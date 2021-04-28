class Solution {
public:
    vector<string> res;
    vector<string> restoreIpAddresses(string s) {
        //回溯，IP每一段无非为1位 2位 3位
        //做三叉树深度优先遍历
        string str;
        back(s, 0, 0, str);
        return res;
    }
    void back(string s, int count, int index, string& str)
    {
        if (index == s.size() || count == 4)
        {
            if (index == s.size() && count == 4)
                res.push_back(str.substr(0, str.size() - 1));
            return;
        }
        //遍历取1位 2位 3位三种情况，相当于三叉树的dfs
        for (int i = 1;i <= 3;i++)
        {
            if (i + index > s.size())   //要取的字符范围越界
                return;
            if (s[index] == '0' && i != 1) //以0开头的两位或三位IP段
                return;
            if (i == 3 && s.substr(index, i) > "255")   //三位地址超过范围
                return;
            str += s.substr(index, i);     //存储当前结果继续深度优先遍历
            str.push_back('.');
            back(s, count + 1, index + i, str);
            str = str.substr(0, str.size() - i - 1);   //回溯，回到上一层节点
        }
    }
};