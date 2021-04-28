class Solution {
public:
    //把所有出现三次的数字的二进制表示的每一位都分别加起来，那么每一位的和都能被3整除
    //把数组中所有数字的二进制表示的每一位加起来，如果某一位的和被3整除，则那个只出现一次的数字二进制表示对应的那一位为0，否则为1.
    int singleNumber(vector<int>& nums) {
        int BitSum[32] = { 0 };
        int n = nums.size();
        for (int i = 0;i < n;i++)
        {
            int bit = 1;
            for (int j = 31;j >= 0;j--)
            {
                int b = nums[i] & bit;
                if (b != 0)
                {
                    BitSum[j] += 1;
                }
                nums[i] = nums[i] >> 1;
            }
        }
        int res = 0;
        for (int i = 0;i < 32;i++)      //每次更新的是res的末位，要先把末位空出来，即res=res<<1
        {
            res = res << 1;
            res += BitSum[i] % 3;
        }
        return res;
    }
};