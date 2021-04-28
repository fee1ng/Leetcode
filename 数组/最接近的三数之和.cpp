class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());  //��������
        int curr = INT_MAX;
        int res = 0;
        for (int i = 0;i < n;i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])     //ȥ��
                continue;
            int k = n - 1;
            int j = i + 1;
            while (j < k)
            {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == target)
                    return target;
                if (abs(sum - target) < curr)
                {
                    curr = abs(sum - target);
                    res = sum;
                }
                //sum>target����c���ƣ�����c��С
                if (sum > target)
                {
                    int k0 = k - 1;
                    while (j < k0 && nums[k0] == nums[k])
                        k0--;
                    k = k0;
                }
                //sum<target������b���ƣ���b����
                else
                {
                    int j0 = j + 1;
                    while (j0 < k && nums[j0] == nums[j])
                        j0++;
                    j = j0;
                }
            }
        }
        return res;
    }
};