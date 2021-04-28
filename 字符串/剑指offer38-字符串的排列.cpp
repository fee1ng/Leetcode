class Solution {
public:
    vector<string> res;
    vector<string> permutation(string s) {

        string curr;
        dfs(s, curr, 0);
        return res;
    }
    //第一步求所有可能出现在第一个位置的字符，即把第一个字符与后面所有字符交换
    //第二步是固定第一个字符，求后面所有字符的全排列，即递归
    //第三步回溯，即把原来的第一个字符交换回来
    //哈希表去重
    void dfs(string& s, string& curr, int index)
    {
        if (index == s.size())
        {
            res.push_back(curr);
            return;
        }
        unordered_set<char> hash;
        for (int i = index;i < s.size();i++)
        {
            if (hash.find(s[i]) != hash.end())
                continue;
            hash.insert(s[i]);
            curr += s[i];
            swap(s[index], s[i]);
            dfs(s, curr, index + 1);
            curr.pop_back();
            swap(s[i], s[index]);
        }
    }
};