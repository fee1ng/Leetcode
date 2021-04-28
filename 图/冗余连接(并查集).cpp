class Solution {
public:
    //把各个节点构建进一个连通图中，若两个节点在遍历当前边之前就已经连通，则该边为使树成环的边，返回
    //构建一个并查集，把连通的节点挂在一个根节点下形成一个连通树
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n + 1);
        for (int i = 1;i <= n;i++)
            parent[i] = i;
        for (auto& e : edges)
        {
            int i = e[0];
            int j = e[1];
            //两个节点未连通，加上该边可以连通，则合并
            if (find(parent, i) != find(parent, j))
                Union(parent, i, j);
            //若两个节点在该边之前已经连通，则加上该边会形成环，应该删去
            else
                return e;
        }
        return {};
    }
    int find(vector<int>& parent, int i)
    {
        if (parent[i] != i)
            parent[i] = find(parent, parent[i]);
        return parent[i];
    }
    void Union(vector<int>& parent, int i, int j)
    {
        parent[find(parent, i)] = find(parent, j);
    }
};