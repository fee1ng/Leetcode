class Solution {
public:
    //water=(j-i)*min(aj,ai)��������*��
    //˫ָ�룬��ʼָ������������ߣ������������֮������С��ȣ��ø߶ȸı䣬���Ƿ񳬹���ǰ�����ֵ
    //˼��ÿ���ƶ���ָ�����ĸ�������Ȼ�Ǹ߶ȵ͵��Ǹ�
    int maxArea(vector<int>& height) {
        int res = 0;
        int water = 0;
        int n = height.size();
        if (n == 0 || n == 1)
            return 0;
        int left = 0, right = n - 1;
        while (left < right)
        {
            water = (right - left) * min(height[right], height[left]);
            res = max(water, res);
            if (height[right] < height[left])
                right--;
            else
                left++;
        }
        return res;
    }
};