class Solution {
public:
    //water=(j-i)*min(aj,ai)，看作高*宽
    //双指针，初始指针在数组的两边，即看作宽最大，之后逐渐缩小宽度，让高度改变，看是否超过当前的最大值
    //思考每次移动的指针是哪个？？显然是高度低的那个
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