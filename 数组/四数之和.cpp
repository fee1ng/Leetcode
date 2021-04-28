class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        //四数之和定下a之后即为三数之和
        //三数之和定下b之后即为两数之和
        //有序数组下两数之和考虑双指针
        vector<vector<int>> res;
        int n = nums.size();
        if (n == 0)
            return res;
        sort(nums.begin(), nums.end());
        for (int i = 0;i < n;i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            for (int j = i + 1;j < n;j++)
            {
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;
                int k = n - 1;
                for (int m = j + 1;m < n;m++)
                {
                    if (m > j + 1 && nums[m] == nums[m - 1])
                        continue;
                    while (m < k && nums[i] + nums[j] + nums[k] + nums[m]>target)
                        k--;
                    if (m == k)
                        break;
                    if (nums[i] + nums[j] + nums[k] + nums[m] == target)
                    {
                        vector<int> v = { nums[i],nums[j],nums[k],nums[m] };
                        res.push_back(v);
                    }

                }
            }
        }
        return res;
    }
};