//����Ҫ��ÿ���ڵ� ���������������ĸ߶Ȳ�ľ���ֵ������ 1�����Կ������м�ڵ���Ϊ���ĸ��ڵ�
//�������飬����ߺ��ұ߷ֱ�������
//�ݹ���ֹ����Ϊleft>right
//���ǽ������Ľڵ��������������Խ����ĺ�����Ҫ����һ���ڵ�
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
    root->left = bulidTree(nums, left, mid - 1);    //������ǰ�ڵ�������������뵱ǰ�ڵ�����
    root->right = bulidTree(nums, mid + 1, right);
    return root;
}