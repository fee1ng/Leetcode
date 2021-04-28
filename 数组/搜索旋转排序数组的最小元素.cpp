class Solution {
public:
    //�ҵ���һ����������
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int res = nums[0];
        for (int i = 0;i < n - 1;i++)
        {
            if (nums[i] > nums[i + 1])
            {
                res = nums[i + 1];
                break;
            }
        }
        return res;
    }
};


class Solution {
public:
    //��������ֻ���������ֲ����������һ��ȫ����������
    //�Ƚ�nums[mid]�����һλԪ��
    //��nums[mid]>nums[right]��˵��mid�ڵ�һ���ֲ��������䣬����СԪ�رض��ڵڶ����ֲ��������䣬��left=mid+1
    //����˵��mid�ڵڶ����ֲ���������������СԪ�ص��ұ߻��Ϊ��СԪ�أ�������right=mid����С�Ұ벿��Χ
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = n - 1;
        while (left < right)
        {
            int mid = (left + right) / 2;
            //��nums[mid]>nums[right]��˵����СԪ����mid���Ұ��
            if (nums[mid] >= nums[n - 1])
            {
                left = mid + 1;
            }
            //�����������
            else
                right = mid;
        }
        return nums[left];
    }
};