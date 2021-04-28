//由于要求每个节点 的左右两个子树的高度差的绝对值不超过 1，所以考虑以中间节点作为树的根节点
//二分数组，在左边和右边分别建立子树
//递归终止条件为left>right
//考虑将建立的节点连接起来，所以建立的函数需要返回一个节点
TreeNode* sortedArrayToBST(vector<int>& nums) {
    TreeNode* root = bulidTree(nums, 0, nums.size() - 1);
    return root;
}
TreeNode* bulidTree(vector<int>& nums, int left, int right)
{
    if (left > right)
        return nullptr;
    int mid = (left + right) / 2;
    TreeNode* root = new TreeNode(nums[mid]);
    root->left = bulidTree(nums, left, mid - 1);    //建立当前节点的左子树，并与当前节点连接
    root->right = bulidTree(nums, mid + 1, right);
    return root;
}