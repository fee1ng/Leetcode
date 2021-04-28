class Solution {
public:
    vector<string> res;
    vector<string> permutation(string s) {

        string curr;
        dfs(s, curr, 0);
        return res;
    }
    //��һ�������п��ܳ����ڵ�һ��λ�õ��ַ������ѵ�һ���ַ�����������ַ�����
    //�ڶ����ǹ̶���һ���ַ�������������ַ���ȫ���У����ݹ�
    //���������ݣ�����ԭ���ĵ�һ���ַ���������
    //��ϣ��ȥ��
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