struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
	
};
void Morris_inorder(TreeNode* root)
{
	TreeNode* cur = root;
	while (cur != nullptr)
	{
		if (cur->left != nullptr)
		{
			TreeNode* pre = cur->left;
			//找到左子树中的最右叶子节点
			while (pre->right != nullptr && pre->right != cur)
			{
				pre = pre->right;

			}
			//找到左子树的最右叶子节点后，如果pre->right为空，将其右节点与cur节点接上
			//此时为第一次到达左子树的最右端
			if (pre->right == nullptr)
			{
				pre->right = cur;
				cur = cur->left;	//移到cur节点
			}
			//不为空则说明pre->right=cur,此时要将线性二叉树恢复为二叉树结构
			//此时为第二次到达左子树的最右端
			else
			{
				pre->right = nullptr;
				cout << cur->val << endl;
				cur = cur->right;
			}
		}
		//如果左子树为空，则遍历根节点及其右子树
		else
		{
			cout << cur->val << endl;
			cur = cur->right;
		}
	}
}