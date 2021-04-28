class Solution {
public:
    //二分法(二叉搜索树既视感)
    //如果nums[mid]<target,则target在右半区间
    //如果nums[mid]>target，则target在左半区间
    //如果相等，则以mid为起点，在左区间找target的起点，右区间找target的终点
    //进行二分的条件是left<right，避免死循环
    //如果left==right，需要特殊判断这个数是否等于target，若等于，则起点终点都相等，即这个数只出现一次
    //因为走到left==right时说明之前都没找到target，说明即使这次找到target它也只会出现一次
    //对size==0和size==1做特例判断
    //写while(left<right)时，退出时为left==right，显然还剩下一个数需要我们判断，这种写法可以考虑边界及在循环体外返回答案
    //若写while(left<=right),退出时为left=right+1，这样会造成死循环或者忽略边界，故一般要在循环体里返回答案。
    vector<int> res = { -1,-1 };
    vector<int> searchRange(vector<int>& nums, int target) {
        int size = nums.size();
        if (size == 0)
            return { -1,-1 };
        if (size == 1)
        {
            if (nums[0] == target)
                return { 0,0 };
            else
                return { -1,-1 };
        }
        help(nums, target, 0, size - 1);
        return res;
    }
    void help(vector<int>& nums, int target, int left, int right)
    {

        if (left < right)
        {
            int mid = (left + right) / 2;
            if (nums[mid] < target)
                help(nums, target, mid + 1, right);
            else if (nums[mid] > target)
                help(nums, target, left, mid);
            else
            {
                int tmp = mid;
                while (mid >= left && nums[mid] == target)
                    mid--;
                res[0] = mid + 1;
                mid = tmp;
                while (mid <= right && nums[mid] == target)
                {
                    mid++;
                }
                res[1] = mid - 1;
            }
        }
        if (left == right)
        {
            if (nums[left] == target)
            {
                res[0] = left;
                res[1] = right;
            }
        }
    }
};