class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        //hash table
        unordered_map<int, int> table;
        int n = nums.size();
        vector<int> res;
        for (int i = 0;i < n;i++)
        {
            table[nums[i]]++;
        }
        for (auto it : table)
        {
            if (it.second > n / 3)
                res.push_back(it.first);
        }
        return res;
    }
};

//算法思想是设置两个候选人以及两个计数器。遍历到和候选人相同时则对应计数器+1，如果和两个候选人都不相同则两个计数器都-1，当一个计数器为0时，更换对应的候选人。
//遍历完剩下的则是2个众数。
//此题我们可以分成三类数： 众数一、众数二和其他数。
//和上面思想一样，遍历时遇到和两个候选人都不一样的值，则是一次互拼
//1.众数一，众数二，其他数 三者拼，都消耗1。
//2.某众数，和2个其他数 三者拼，某众数消耗1，其他数消耗2.
class Solution {
public:
    //抵消阶段：两个不同投票进行对坑，并且同时抵消掉各一张票，如果两个投票相同，则累加可抵消的次数；
    //计数阶段：在抵消阶段最后得到的抵消计数只要不为 0，那这个候选人是有可能超过一半的票数的，为了验证，则需要遍历一次，统计票数，才可确定。
    //如果至多选一个代表，那他的票数至少要超过一半（1/2）的票数；
    //如果至多选两个代表，那他们的票数至少要超过(1/3)的票数；
    //如果至多选m个代表，那他们的票数至少要超过 [ 1 / (m + 1) ] 的票数。
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> res;
        int n = nums.size();
        int v1 = nums[0];
        int v2 = nums[0];
        int count1 = 0, count2 = 0;
        //投票阶段，当前元素匹配两个数，若相同则票数增加，不同则抵消
        //当两个数的票数为0时，则需更新新的数
        for (int curr : nums)
        {
            if (curr == v1)
            {
                count1++;
                continue;
            }
            if (curr == v2)
            {
                count2++;
                continue;
            }
            if (count1 == 0)
            {
                v1 = curr;
                count1++;
                continue;
            }
            if (count2 == 0)
            {
                v2 = curr;
                count2++;
                continue;
            }
            count1--;
            count2--;
        }

        //统计阶段
        count1 = 0, count2 = 0;
        for (int curr : nums)
        {
            if (curr == v1)
                count1++;
            else if (curr == v2)
                count2++;
        }
        if (count1 > n / 3)
            res.push_back(v1);
        if (count2 > n / 3)
            res.push_back(v2);
        return res;
    }
};