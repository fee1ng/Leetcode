class Solution {
public:
    //双边移动,快速排序
    vector<int> sortArray(vector<int>& nums) {
        quicksort(nums, 0, nums.size() - 1);
        return nums;
    }
    void quicksort(vector<int>& v, int L, int R)
    {
        if (L < R)
        {
            int mid = help(v, L, R);
            quicksort(v, L, mid - 1);
            quicksort(v, mid + 1, R);
        }
    }
    int help(vector<int>& nums, int L, int R)
    {
        int i = L + 1, j = R;
        int key = nums[L];
        while (1)
        {
            while (i <= j && nums[i] <= key)
                i++;
            while (i <= j && nums[j] >= key)
                j--;
            if (i > j)
                break;
            swap(nums[i], nums[j]);
        }
        //此时，j的位置即为key的位置
        swap(nums[j], nums[L]);
        return j;
    }
};


    class Solution {
    public:
        vector<int> sortArray(vector<int>& nums) {
            quicksort(nums, 0, nums.size() - 1);
            return nums;
        }
        void quicksort(vector<int>& nums, int L, int R)
        {
            if (L < R)
            {
                int mid = help(nums, L, R);
                quicksort(nums, L, mid - 1);
                quicksort(nums, mid + 1, R);
            }
        }
        int help(vector<int>& nums, int L, int R)
        {
            int key = nums[R];
            int i = L, j = L;    //i指向位置会与下一个小于key的nums[j]交换
            //j指向当前遍历的数，如果小于key则交换
            //结束时i的位置就是key的位置，i左边都为小于key，,右边都大于key
            for (;j < R;j++)
            {
                if (nums[j] < key)
                {
                    swap(nums[i], nums[j]);
                    i++;
                }
            }
            nums[R] = nums[i];    //原本第i位数放到最后
            nums[i] = key;        //让key到该去的位置
            return i;
        }
    };