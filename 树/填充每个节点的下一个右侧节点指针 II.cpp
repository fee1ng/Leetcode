//≤„–Ú±È¿˙
Node* connect(Node* root) {
    if (root == nullptr)
        return nullptr;
    queue<Node*> q;
    q.push(root);
    while (!q.empty())
    {
        int size = q.size();
        while (size--)
        {
            Node* curr = q.front();
            q.pop();
            if (size >= 1)
            {
                curr->next = q.front();
            }
            else
                curr->next = nullptr;
            if (curr->left != nullptr)
                q.push(curr->left);
            if (curr->right != nullptr)
                q.push(curr->right);
        }

    }
    return root;
}