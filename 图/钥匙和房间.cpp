class Solution {
public:
    //bfs
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        queue<int> q;
        int n = rooms.size();
        vector<int> visit(n);
        q.push(0);
        visit[0] = 1;
        while (!q.empty())
        {
            int curr = q.front();
            q.pop();
            for (auto& i : rooms[curr])
            {
                if (!visit[i])
                {
                    q.push(i);
                    visit[i] = 1;
                }
            }
        }
        for (int i = 0;i < n;i++)
        {
            if (visit[i] == 0)
                return false;
        }
        return true;
    }
};