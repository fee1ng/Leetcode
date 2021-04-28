class Solution {
public:
    //排序，分情况讨论
    //1.如果nums[i+1]==nums[i]+1,当前连续长度自增，取历史最大连续长度和当前连续长度较大者为结果
    //2.如果nums[i+1]==nums[i],不变
    //否则，当前连续长度=1
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if (n == 0)
            return 0;
        int res = 1;
        int curr = 1;
        for (int i = 0;i < n - 1;i++)
            if (nums[i + 1] == nums[i] + 1)
            {
                curr++;
                res = max(curr, res);
            }
            else if (nums[i + 1] == nums[i])
                continue;
            else
                curr = 1;
        return res;
    }
};



class Solution {
public:
    //hash map,查找nums[i]+1是否在哈希表中
    //同时，若nums[i]-1也在哈希表中，则不做判断，因为由nus[i]生成的连续序列为nums[i]-1生成序列的字串
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hash;
        for (auto& n : nums)
            hash.insert(n);
        int res = 0;
        for (auto& i : nums)
        {
            if (!hash.count(i) - 1)
            {
                int curr = 1;
                int currentNum = i;
                while (hash.count(currentNum + 1))
                {
                    curr++;
                    currentNum++;
                }
                res = max(res, curr);
            }
        }
        return res;
    }
};