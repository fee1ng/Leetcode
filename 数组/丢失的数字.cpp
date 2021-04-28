class Solution {
public:
    //���򣬷��������
    //1.0����������λ
    //2.1-n��ĳ����û����
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
        //һ���������=0�����Ȱ������е��������һ�飬�ٶ����������[0,n]�ϵ������
        //�������ֹ��������������=0��ʣ�µ�����Ϊû���ֵ�

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