class Solution {
public:
    //二分查找的关键:1.左半边或右半边为绝对递增数列    2.是否小于nums[mid]的数都在左半边区间内
    //二分查找的关键在于必须对有序数组进行查找，但该题是两个有序数组，但不知道当前mid的左边还是右边是有序数组
    //找到mid的左边或右边的有序数组，优先在有序数组里寻找(注意在有序数组里的条件是target<右区间但>=左区间)，找不到丢给另一边处理
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 1)
        {
            if (nums[0] == target)
                return 0;
            else
                return -1;
        }
        int left = 0, right = n - 1;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (nums[mid] == target)
                return mid;
            //如果mid的左半边是有序的，那么右半边必是无序的
            //则优先考虑在左半边寻找的情况，即target<nums[mid]&&nums[0]<=target，若不成立，则丢给右半边处理
            //以[4,5,6,7,0,1,2]为例，一开始mid=3,nums[mid]=6且target=0<nums[mid]，但并不一定target就在mid的左边，因为左区间的左边界有可能不够小
            //所以需要判断左边界是否足够小在判断是否丢进左区间计算
            if (nums[0] <= nums[mid])
            {
                if (target < nums[mid] && nums[0] <= target)
                {
                    right = mid - 1;
                }
                else
                    left = mid + 1;
            }
            //反之，右半边有序，则左半边必无序，优先考虑在右半边寻找的情况，即nums[mid]<target&&taget<=nums[n-1]
            //若不成立，则答案必在左半边，丢给左半边去处理
            else
            {
                if (nums[mid] < target && target <= nums[n - 1])
                {
                    left = mid + 1;
                }
                else
                    right = mid - 1;
            }
        }
        return -1;
    }
};