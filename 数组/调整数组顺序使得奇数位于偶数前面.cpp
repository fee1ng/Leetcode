class Solution {
public:
    //申请一个新数组
    vector<int> exchange(vector<int>& nums) {
        int n = nums.size();
        vector<int> v(n);
        int a = 0, b = n - 1;
        for (int i = 0;i < n;i++)
        {
            if (nums[i] % 2 == 0)
            {
                v[b--] = nums[i];
            }
            else
            {
                v[a++] = nums[i];
            }
        }
        return v;
    }
};

class Solution {
public:
    //原地修改，两边逼近
    vector<int> exchange(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = n - 1;
        while (1)
        {
            while (i <= j && nums[i] % 2 != 0)
                i++;
            while (i <= j && nums[j] % 2 == 0)
                j--;
            if (i > j)
                break;
            swap(nums[i], nums[j]);
        }
        return nums;
    }
};