class Solution {
public:
    //回溯遍历一颗二叉树，即A.选择当前第n位数字，B.不选择这个数，选择第n+1个数。不剪枝
    //深度优先搜索的退出条件为target==0,即找到结果，或者数组被用完。
    //数组被用完的极端例子即数组中的每个数都不选，那么到最后target还在，但是要退出，因为没得选了。
    //第n位数可以考虑用或不用，即选择进行遍历下一层或在当前层进行尝试
    vector<vector<int>> res;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        if (n == 0)
            return res;
        vector<int> v;
        help(candidates, target, v, 0);
        return res;
    }
    void help(vector<int>& candidates, int target, vector<int>& v, int n)
    {
        if (n == candidates.size())
            return;
        if (target == 0)
        {
            res.push_back(v);
            return;
        }
        help(candidates, target, v, n + 1);  //不选第n个数
        //选第n个数
        if (candidates[n] <= target)
        {
            target -= candidates[n];
            v.push_back(candidates[n]);
            help(candidates, target, v, n);     //下次还从这里开始，因为数字可以重复使用
            v.pop_back();
        }
    }
};


class Solution {
public:
    vector<vector<int>> res;
    //回溯遍历一个candidates.size()-index叉树
    //去重方法：同一层的第二个节点以后不遍历之前节点已经遍历过的数，例如:
    //[2,3,6,7]的第二层第二个节点3不再将2加入尝试数组中。即消去[2,2,3]的重复[3,2,2]
    //[2,3,6,7]的第三层第二个个节点3不再遍历2，即消去[2,2,3]的重复[2,3,2]
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> v;
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, v, 0);
        return res;
    }
    void dfs(vector<int>& candidates, int  target, vector<int>& v, int index)
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
            if (candidates[i] <= target)
            {
                v.push_back(candidates[i]);
                dfs(candidates, target - candidates[i], v, i);
                v.pop_back();
            }
        }
    }
};