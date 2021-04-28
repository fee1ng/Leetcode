class Solution {
public:
    //相同的数字与自身异或救国为0
    //把原数组分成两个数组，使得每个子数组只包含一个只出现一次的数组，则异或的结果即为这个数字
    //分成两个数组的标准是两个只出现一次的数字a,b异或的结果中第一个出现1的位(因为它不可能是0，所以有1的位)
    //1.求XorRes=(a xor b)的值，即整个数组的数异或
    //2.找出XorRes中第一个出现1的位，记为index(通过(XorRes&1)的值是否为1判断，否则右移)
    //3.判断数组中元素nums[i]的第index位是否为1，分为两个数组统计
    //4.返回由两个数组异或结果组成的数组
    vector<int> singleNumbers(vector<int>& nums) {
        int XorRes = 0;
        int n = nums.size();
        for (int i = 0;i < n;i++)
        {
            XorRes = nums[i] ^ XorRes;
        }
        int index = find(XorRes);
        int r1 = 0, r2 = 0;
        for (int i = 0;i < n;i++)
        {
            if (IsBitOne(nums[i], index))
                r1 = r1 ^ nums[i];
            else
                r2 = r2 ^ nums[i];
        }
        vector<int> res(2);
        res[0] = r1, res[1] = r2;
        return res;
    }
    int find(int n)
    {
        int index = 0;
        while (((n & 1) == 0) && (index < 8 * sizeof(int)))
        {
            n = n >> 1;
            ++index;
        }
        return index;
    }
    bool IsBitOne(int n, int index)
    {
        n = n >> index;
        if ((n & 1) == 0)
            return false;
        else
            return true;
    }
};