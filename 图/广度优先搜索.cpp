class Solution {
public:
    bool findWhetherExistsPath(int n, vector<vector<int>>& graph, int start, int target) {
        queue<int> q;
        if (n == 0)
            return false;
        unordered_map<int, vector<int>> table;
        vector<int> visit(n);
        for (auto& i : graph)
        {
            table[i[0]].push_back(i[1]);
        }
        q.push(start);
        while (!q.empty())
        {
            int curr = q.front();
            q.pop();
            for (auto& i : table[curr])
            {
                if (visit[i] == 0)
                    q.push(i);
                visit[i] = 1;
                if (i == target)
                    return true;
            }
        }
        return false;
    }
};