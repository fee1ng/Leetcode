class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return 0;
        int left = 0, right = n - 1;
        while (left < right)
        {
            int mid = (left + right) / 2;
            if (nums[mid] > nums[right])
                left = mid + 1;
            else if (nums[mid] < nums[right])
                right = mid;
            //��nums[mid]==nums[right]��������ͬԪ�صĴ��ڣ����ǲ���֪����СԪ�ص�����mid����һ�ߣ�������ȷ�������ұ߽���Ԫ�ؿ��Ա�������ʲ�Ҫ�ұ߽磬��right--
            else
            {
                right--;
            }
        }
        return nums[left];
    }
};