/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> v;
        dfs(root,sum,v,0);
        return res;
    }
    void dfs(TreeNode* root,int sum,vector<int> v,int s)
    {
        if(root==nullptr)
            return;
        if(root->left==nullptr&&root->right==nullptr)
        {
            v.push_back(root->val);
            s+=root->val;
            if(s==sum)
                res.push_back(v);
            return;
        }
        s+=root->val;
        v.push_back(root->val);
        dfs(root->left,sum,v,s);
        dfs(root->right,sum,v,s);
    }
};
// @lc code=end

