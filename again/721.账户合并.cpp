/*
 * @lc app=leetcode.cn id=721 lang=cpp
 *
 * [721] 账户合并
 */

// @lc code=start
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int find(vector<int>& parent,int i)
    {
        if(parent[i]!=i)
            parent[i]=find(parent,parent[i]);
        return parent[i];
    }
    void merge(vector<int>& parent,int i,int j)
    {
        parent[find(parent,i)]=find(parent,parent[j]);
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string,int> email_index;
        unordered_map<string,string> email_name;
        int email_count=0;
        for(int i=0;i<accounts.size();i++)
        {   
            string name=accounts[i][0];
            for(int j=1;j<accounts[i].size();j++)
            {   
                string email=accounts[i][j];
                if(email_index.find(email)==email_index.end())
                {
                    email_index[email]=email_count++;
                    email_name[email]=name;
                }
            }
        }
        int n=email_index.size();
        vector<int> parent(n);
        for(int i=0;i<n;i++)
            parent[i]=i;
        vector<string> acc;
        
    }
};
// @lc code=end

