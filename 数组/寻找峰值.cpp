class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return 0;
        if (n == 2)
        {
            if (nums[0] > nums[1])
                return 0;
            else
                return 1;
        }
        for (int i = 1;i < n;i++)
        {
            if (i < n - 1)
            {
                if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1])
                    return i;
            }
            else
            {
                if (nums[i] > nums[i - 1])
                    return i;
            }
        }
        return 0;
    }
};


class Solution {
public:
    //���ֲ���
    //����Ԫ��ǡ��λ���������л���һ���ֲ������¶���(nums[i]<nums[i+1]))����˵����ֵ���ڱ�Ԫ�ص��ұߡ�
    //����Ԫ��ǡ��λ�ڽ������л���һ���ֲ��½��¶���(nums[i]>nums[i+1])����˵����ֵ�ڱ�Ԫ����ߡ�
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = n - 1;
        while (left < right)
        {
            int mid = (left + right) / 2;
            if (nums[mid] > nums[mid + 1])   //��ֵ�ڱ�Ԫ��(������Ԫ�����)
                right = mid;
            else                        //��ֵ�϶��ڱ�Ԫ���ұ��ҿ϶����Ǳ�Ԫ��
                left = mid + 1;
        }
        return left;
    }
};