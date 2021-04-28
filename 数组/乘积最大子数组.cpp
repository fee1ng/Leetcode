class Solution {
public:
    //��̬�滮
    //�����ڴ��ڸ�������ô�ᵼ�����ı���С�ģ���С�ı����ġ���˻���Ҫά����ǰ��Сֵimin
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return 0;
        vector<int> dpMax(n);
        vector<int> dpMin(n);
        dpMax[0] = nums[0], dpMin[0] = nums[0];
        int res = nums[0];
        for (int i = 1;i < n;i++)
        {
            dpMax[i] = max(dpMax[i - 1] * nums[i], max(nums[i], dpMin[i - 1] * nums[i]));
            dpMin[i] = min(dpMin[i - 1] * nums[i], min(nums[i], dpMax[i - 1] * nums[i]));
        }
        return *max_element(dpMax.begin(), dpMax.end());
    }
};