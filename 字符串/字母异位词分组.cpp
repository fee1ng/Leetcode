class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;
        int n = strs.size();
        vector<vector<string>> res;
        for (int i = 0;i < n;i++)
        {
            string curr = strs[i];
            string tmp = strs[i];
            sort(curr.begin(), curr.end());
            m[curr].push_back(tmp);
        }
        for (auto it : m)
        {
            res.push_back(it.second);
        }
        return res;
    }
};