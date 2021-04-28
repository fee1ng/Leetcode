class Solution {
public:
    //组合总数，树的遍历
    //规则为是否选当前指向数组的元素
    vector<vector<int>> res;
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> v;
        dfs(nums, v, 0);
        res.push_back({});
        return res;
    }
    void dfs(vector<int>& nums, vector<int>& v, int i)
    {
        if (i == nums.size())
            return;
        //不选当前元素
        dfs(nums, v, i + 1);
        //选当前元素
        v.push_back(nums[i]);
        dfs(nums, v, i + 1);
        //加入结果集
        res.push_back(v);
        //回溯
        v.pop_back();
    }
};



class Solution {
public:
    vector<int> t;
    vector<vector<int>> ans;

    vector<vector<int>> subsets(vector<int>& nums)
    {
        int n = nums.size();
        //mask的二进制位有n位，当前mask的二进制位j为1，则将数组中第j个数加入结果数组
        //2^n=mask，即长度为3的数组有8个子集，每一个mask代表一个子集状态，mask的二进制有3位
        for (int mask = 0; mask < (1 << n); ++mask)
        {
            t.clear();
            for (int i = 0; i < n; ++i)                 //遍历数组的每一位
            {
                //如果mask的二进制某一位为1，则将数组中的该位加入数组
                if (mask & (1 << i))
                {
                    t.push_back(nums[i]);
                }
            }
            ans.push_back(t);
        }
        return ans;
    }
};