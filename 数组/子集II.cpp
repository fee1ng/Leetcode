class Solution {
public:
    //dfs,先排序，后遍历一颗num.size()-i叉树
    //i指向数组遍历的位置
    vector<vector<int>> res;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> curr;
        int n=nums.size();
        dfs(nums,curr,0,n);
        res.push_back({});
        return res;
    }
    void dfs(vector<int>& nums,vector<int>& curr,int i,int n)
    {
        if(i==n)
            return;
        for(int j=i;j<n;j++)
        {
            if(j>i&&nums[j]==nums[j-1])
                continue;
            curr.push_back(nums[j]);
            dfs(nums,curr,j+1,n);
            res.push_back(curr);
            curr.pop_back();
        }
    }
};