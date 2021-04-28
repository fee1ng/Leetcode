class Solution {
public:
    //key-value
    int findRepeatNumber(vector<int>& nums) {
        unordered_map<int, int> m;
        int n = nums.size();
        if (n == 0)
            return -1;
        int i;
        for (i = 0;i < n;i++)
        {
            m[nums[i]]++;
            if (m[nums[i]] > 1)
                break;
        }
        return nums[i];
    }
};


class Solution {
public:
    //长度为n的数组，数字范围在0-n-1,则说明若没重复，排好序的数字应该nums[i]=i
    //扫描数组中的每个数字，当扫描到的下标为i,记nums[i]=m
    //首先比较m与i是否相等，相等则扫描下一位数字
    //不相等则与nums[m]比较，若相等则返回，不相等则交换数值,继续比较
    //使用一次遍历的原因是如果有重复数字，那么第一次把nums[m]和nums[i]交换后，会有nums[i]=i，
    //那么第二次找到这个重复数字时，就有m==nums[m]
    int findRepeatNumber(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return -1;
        for (int i = 0;i < n;i++)
        {
            int m = nums[i];
            if (m == i)
                continue;
            else
            {
                if (m == nums[m])
                    return m;
                else
                    swap(nums[m], nums[i]);
            }
        }
        return -1;
    }
    void swap(int& a, int& b)
    {
        int temp = a;
        a = b;
        b = temp;
    }
};


class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        int n = nums.size();
        //构建nums[i]=i的一一对应
        for (int i = 0;i < n;i++)
        {
            while (nums[i] != i)
            {
                if (nums[i] == nums[nums[i]])
                    return nums[i];
                int temp = nums[i];   //i=1,temp=3
                nums[i] = nums[temp]; //保存nums[temp]
                nums[temp] = temp;    //构建nums[3]=3
            }
        }
        return -1;
    }
};