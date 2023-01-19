class Solution
{
public:
    int findPairs(vector<int> &nums, int k)
    {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]]++;
        }
        int ans = 0;
        for (auto i : mp)
        {
            if ((k > 0 && mp.find(i.first + k) != mp.end()) || (k == 0 && i.second > 1))
            {
                ans++;
            }
        }
        return ans;
    }
};