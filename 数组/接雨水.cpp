class Solution {
public:
    //双指针
    //能接的雨水取决于当前位置高度与最高高度的差值
    //从左右两边遍历，直到left==right，维护left_max与right_max的值
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0)
            return 0;
        int left = 0, right = n - 1;
        int res = 0;
        int left_max = -1, right_max = -1;
        while (left < right)
        {   
            //若left_max<right_max，则积水方向从左至右算，积水取决于left_max与当前height的差值
            if (height[left] < height[right])           
            {
                if (height[left] > left_max)    //这是不可能有积水的，但是要更新left_max
                    left_max = height[left];
                else
                    res += left_max - height[left];
                left++;
            }
            //反之相同
            else
            {
                if (height[right] > right_max)
                    right_max = height[right];
                else
                    res += right_max - height[right];
                right--;
            }
        }
        return res;
    }
};


//双指针二:
class Solution {
public:
    //双指针
    //能接的雨水取决于当前位置高度与最高高度的差值
    //从左右两边遍历，直到left==right，维护left_max与right_max的值
    //定理一：在某个位置i处，它能存的水，取决于它左右两边的最大值中较小的一个。
    //定理二：当我们从左往右处理到left下标时，左边的最大值left_max对它而言是可信的，但right_max对它而言是不可信的。（见下图，由于中间状况未知，对于left下标而言，right_max未必就是它右边最大的值）
    //定理三：当我们从右往左处理到right下标时，右边的最大值right_max对它而言是可信的，但left_max对它而言是不可信的。
    /*对于位置left而言，它左边最大值一定是left_max，右边最大值“大于等于”right_max，这时候，如果left_max<right_max成立，
    那么它就知道自己能存多少水了。无论右边将来会不会出现更大的right_max，都不影响这个结果。
    所以当left_max<right_max时，我们就希望去处理left下标，反之，我们希望去处理right下标。*/
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0)
            return 0;
        int left = 0, right = n - 1;
        int res = 0;
        int left_max = 0, right_max = 0;
        while (left < right)
        {
            //若left_max<right_max，则积水方向从左至右算，积水取决于left_max与当前height的差值
            if (left_max < right_max)
            {
                if (height[left] > left_max)    //这是不可能有积水的，但是要更新left_max
                    left_max = height[left];
                else
                {
                    res += left_max - height[left];
                    left++;
                }
            }
            //反之相同
            else
            {
                if (height[right] > right_max)
                    right_max = height[right];
                else
                {
                    res += right_max - height[right];
                    right--;
                }
            }
        }
        return res;
    }
};
//动态规划
class Solution {
public:
    //动态规划维护当前位置的left_max和right_max
    //当前位置能接雨水的数量=min(left_max,right_max)-height[i]
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0)
            return 0;
        vector<int> left(n);    //当前位置的left_max和right_max
        vector<int> right(n);
        int res = 0;
        left[0] = height[0];
        right[n - 1] = height[n - 1];
        for (int i = 1;i < n;i++)
            left[i] = max(left[i - 1], height[i]);   //当前位置的left_max=前一个位置的left_max和当前高度的较大者
        for (int i = n - 2;i >= 0;i--)
            right[i] = max(right[i + 1], height[i]);
        for (int i = 1;i < n;i++)
            res += min(left[i], right[i]) - height[i];
        return res;
    }
};