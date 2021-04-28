class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> m;
        int n = nums.size();
        for (int i = 0;i < n;i++)
        {
            m[nums[i]]++;
            if (m[nums[i]] > 1)
                return true;
        }
        return false;
    }
};



class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 1;i < n;i++)
        {
            if (nums[i] == nums[i - 1])
                return true;
        }
        return false;
    }
};