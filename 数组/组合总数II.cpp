class Solution {
public:
    //每个元素只能使用一次，说明每次选择的遍历的数组初始下标index之前的数不能使用
     //[2,3,6,7] index=1时，只有三种选择，即3,6,7
    //解集不能有重复组合，则需要将数组进行排序，若当前遍历的数字==前一次遍历的数字，则跳过
    //[2,2,3,6,7],初始root节点遍历第一个2结束后i=1，要遍历第二个2时要去重，即continue
    //回溯遍历一颗candidates.size()-index叉树，注意排序去重
    vector<vector<int>> res;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n = candidates.size();
        if (n == 0)
            return res;
        vector<int> v;
        sort(candidates.begin(), candidates.end());
        help(candidates, target, v, 0);
        return res;
    }
    void help(vector<int>& candidates, int target, vector<int>& v, int index)
    {
        if (target == 0)
        {
            res.push_back(v);
            return;
        }
        if (index == candidates.size())
            return;
        for (int i = index;i < candidates.size();i++)
        {
            if (i > index && candidates[i] == candidates[i - 1])
                continue;
            if (candidates[i] <= target)
            {
                v.push_back(candidates[i]);
                help(candidates, target - candidates[i], v, i + 1);
                v.pop_back();
            }
            else
                break;
        }
    }
};