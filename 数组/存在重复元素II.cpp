class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        //key=nums[i]
        //value=i
        unordered_map<int, int> m;
        int size = nums.size();
        for (int i = 0;i < size;i++)
        {
            auto it = m.find(nums[i]);
            if (it == m.end())
                m.insert({ nums[i],i });
            else
            {
                if (i - it->second <= k)
                    return true;
                else
                    it->second = i;
            }
        }
        return false;
    }
};