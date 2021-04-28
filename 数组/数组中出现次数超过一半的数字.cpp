class Solution {
public:
    //hash
    int majorityElement(vector<int>& nums) {
        int size = nums.size();
        unordered_map<int, int> m;
        for (int i = 0;i < size;i++)
        {
            m[nums[i]]++;
            if (m[nums[i]] > size / 2)
                return nums[i];
        }
        return 0;
    }
};

class Solution {
public:
    //摩尔投票,因为要找的数字出现次数比其他数字出现的次数都多，则结果必为最后vote>0代表的那个数
    //如果当前一位和res相同，则vote++
    //如果当前一位和res不同，则vote--
    //如果vote==0，则res=nums[i]
    int majorityElement(vector<int>& nums) {
        int res = 0, MoleVote = 0;
        int n = nums.size();
        for (int i = 0;i < n;i++)
        {
            if (MoleVote == 0)
                res = nums[i];
            if (nums[i] != res)
                MoleVote--;
            else
                MoleVote++;
        }
        return res;
    }
};

//超出时间限制
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //如果一个数字超过一半，则排好序的数组该数字在中间(n/2)
        //参考快速排序，每一次将一个数字放到合适的地方，使得左<key<右
        int n = nums.size();
        if (n == 1 || n == 2)
            return nums[0];
        int mid = n / 2;
        int start = 0, end = n - 1;
        int index = help(nums, 0, n - 1);
        while (index != mid)
        {
            if (index > mid)
            {
                end = index - 1;
                index = help(nums, start, end);
            }
            else
            {
                start = index + 1;
                index = help(nums, start, end);
            }
        }
        int res = nums[mid];
        return res;
    }
    int help(vector<int>& nums, int left, int right)
    {
        int key = nums[left];
        int i = left + 1, j = right;
        while (i <= j)
        {
            while (i <= j && nums[i] <= key)
                i++;
            while (i <= j && nums[j] >= key)
                j--;
            if (i > j)
                break;
            swap(nums[i], nums[j]);
        }
        nums[left] = nums[j];
        nums[j] = key;
        return j;
    }
};