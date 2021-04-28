class Solution {
public:
    bool isStraight(vector<int>& nums) {
        int f1 = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0;i < 4;i++)
        {
            if (nums[i] == 0)
            {
                f1++;
                continue;
            }
            if (nums[i] == nums[i + 1])
                return false;
            if (nums[i] + 1 != nums[i + 1])
            {
                if (nums[i + 1] - nums[i] > 3)
                    return false;
                if (f1)
                {
                    if (f1 == 1 && nums[i] + 2 != nums[i + 1])
                        return false;
                    //else if(f1==2&&nums[i]+3!=nums[i+1])
                        //return false;
                    f1--;
                }
                else
                    return false;
            }
        }
        return true;
    }
};