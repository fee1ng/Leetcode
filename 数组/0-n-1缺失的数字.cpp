class Solution {
public:
    //num[i]=i
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0;i < n;i++)
            if (nums[i] != i)
                return i;
        return n;
    }
};