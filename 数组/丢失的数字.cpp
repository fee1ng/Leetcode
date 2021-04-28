class Solution {
public:
    //排序，分情况讨论
    //1.0不出现在首位
    //2.1-n中某数字没出现
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
        {
            if (nums[0] == 1)
                return 0;
            else
                return 1;
        }

        sort(nums.begin(), nums.end());

        if (nums[0] != 0)
            return 0;

        int i;
        for (i = 0;i < n - 1;i++)
        {
            if (nums[i + 1] - nums[i] != 1)
                break;
        }
        return nums[i] + 1;
    }
};



class Solution {
public:
    int missingNumber(vector<int>& nums) {
        //xor
        //一个数异或本身=0，故先把数组中的数都异或一遍，再对上述结果与[0,n]上的数异或
        //其他出现过的数异或了两遍=0，剩下的数即为没出现的

        int res = 0;
        int n = nums.size();
        for (int i = 0;i < n;++i)
        {
            res ^= nums[i];
        }
        for (int i = 0;i <= n;i++)
        {
            res = res ^ i;
        }
        return res;
    }
};