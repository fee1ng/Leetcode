class Solution {
public:
    //�Ѹ����ڵ㹹����һ����ͨͼ�У��������ڵ��ڱ�����ǰ��֮ǰ���Ѿ���ͨ����ñ�Ϊʹ���ɻ��ıߣ�����
    //����һ�����鼯������ͨ�Ľڵ����һ�����ڵ����γ�һ����ͨ��
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n + 1);
        for (int i = 1;i <= n;i++)
            parent[i] = i;
        for (auto& e : edges)
        {
            int i = e[0];
            int j = e[1];
            //�����ڵ�δ��ͨ�����ϸñ߿�����ͨ����ϲ�
            if (find(parent, i) != find(parent, j))
                Union(parent, i, j);
            //�������ڵ��ڸñ�֮ǰ�Ѿ���ͨ������ϸñ߻��γɻ���Ӧ��ɾȥ
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