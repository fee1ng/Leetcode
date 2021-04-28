class Solution {
public:
    //��ͬ���������������ȹ�Ϊ0
    //��ԭ����ֳ��������飬ʹ��ÿ��������ֻ����һ��ֻ����һ�ε����飬�����Ľ����Ϊ�������
    //�ֳ���������ı�׼������ֻ����һ�ε�����a,b���Ľ���е�һ������1��λ(��Ϊ����������0��������1��λ)
    //1.��XorRes=(a xor b)��ֵ������������������
    //2.�ҳ�XorRes�е�һ������1��λ����Ϊindex(ͨ��(XorRes&1)��ֵ�Ƿ�Ϊ1�жϣ���������)
    //3.�ж�������Ԫ��nums[i]�ĵ�indexλ�Ƿ�Ϊ1����Ϊ��������ͳ��
    //4.���������������������ɵ�����
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