class Solution {
public:
    //�����г������ε����ֵĶ����Ʊ�ʾ��ÿһλ���ֱ����������ôÿһλ�ĺͶ��ܱ�3����
    //���������������ֵĶ����Ʊ�ʾ��ÿһλ�����������ĳһλ�ĺͱ�3���������Ǹ�ֻ����һ�ε����ֶ����Ʊ�ʾ��Ӧ����һλΪ0������Ϊ1.
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
        for (int i = 0;i < 32;i++)      //ÿ�θ��µ���res��ĩλ��Ҫ�Ȱ�ĩλ�ճ�������res=res<<1
        {
            res = res << 1;
            res += BitSum[i] % 3;
        }
        return res;
    }
};