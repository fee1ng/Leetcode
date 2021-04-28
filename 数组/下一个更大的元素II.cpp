class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        //naive,数组扩容2倍，并首尾相连，构建数组[1,2,3]->[1,2,3,1,2,3] O(n^2)
        int n = nums.size();
        nums.resize(2 * n);
        int j = 0;
        for (int i = n;i < 2 * n;i++, j++)
            nums[i] = nums[j];
        vector<int> res(n);
        for (int i = 0;i < n;i++)
        {
            int flag = 0;
            for (int j = i + 1;j < 2 * n;j++)
            {
                if (nums[i] < nums[j])
                {
                    res[i] = nums[j];
                    flag = 1;
                    break;
                }
            }
            if (flag == 0)
                res[i] = -1;
        }
        return res;
    }
};

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        //单调递减栈，使得站里都是递减元素的下标
        int n = nums.size();
        nums.resize(2 * n);
        int j = 0;
        for (int i = n;i < 2 * n;i++, j++)
            nums[i] = nums[j];
        vector<int> res(n, -1);
        stack<int> minstk;
        int i = 0;
        while (i < 2 * n)
        {   
            //栈顶值大于等于当前值，说明当前值不是下一个更大元素，入栈，i++
            if (minstk.empty() || nums[minstk.top()] >= nums[i])
                minstk.push(i++);
            //当前值是栈里一部分元素的下一个更大元素，则更新res数组，出栈，但i不自增，因为当前值可能是栈内一部分元素的下一个更大元素
            else
            {   
                //注意求余防止越界
                res[minstk.top() % n] = nums[i];
                minstk.pop();
            }
        }

        return res;
    }
};