/*二叉搜索树中的两个节点被错误地交换。

请在不改变其结构的情况下，恢复这棵树。*/
//二叉搜索树中序遍历得到应该是有序数组，在数组中找出a[i]>a[i+1]的两个数
//整个值序列中不满足条件的位置或者有两个，或者有一个。
//如果有两个不满足条件的位置i,j，则对应的错误节点为a[i]和a[j+1]，记录下来x,y
//如果只有一个不满足条件的位置i，则为a[i]和a[i+1]，记录x,y
//在二叉搜索树中找到x,y，交换

vector<int> v;
void recoverTree(TreeNode* root) {
    if (root == nullptr)
        return;
    dfs(root);
    int x = -1, y = -1;
    for (int i = 0;i < v.size() - 1;i++)
    {
        if (v[i] > v[i + 1])
        {
            y = v[i + 1];
            if (x == -1)
                x = v[i];
            else
                break;
        }
    }
    //找到错误的x,y
    //在二叉搜索树中交换x,y
    swap(root, x, y, 2);
}
void swap(TreeNode* root, int x, int y, int count)
{
    if (root == nullptr)
        return;
    if (root->val == x || root->val == y)
    {
        root->val = root->val == x ? y : x;     
        //if(--count==0)
            //return;
    }
    swap(root->left, x, y, count);
    swap(root->right, x, y, count);
}
//中序遍历
void dfs(TreeNode* root)
{
    if (root == nullptr)
        return;
    dfs(root->left);
    v.push_back(root->val);
    dfs(root->right);
}