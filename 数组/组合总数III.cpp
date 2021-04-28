class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> v;
        dfs(k, n, 1, v);
        return res;
    }
    //�ݹ���ݣ�ȷ����������Ϊk==v.size()&&n==0
    void dfs(int k, int n, int index, vector<int>& v)
    {
        if (v.size() == k && n == 0)
        {
            res.push_back(v);
            return;
        }
        if (v.size() > k || n < 0)
            return;
        //ע�����������Ҫд���ˣ���i����index
        for (int i = index;i < 10;i++)
        {
            if (n - i < 0)
                return;
            v.push_back(i);
            dfs(k, n - i, i + 1, v);
            v.pop_back();
        }
    }
};