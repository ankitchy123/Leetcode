class Solution
{
public:
    vector<int> findLonely(vector<int> &nums)
    {
        map<int, int> mp;
        for (int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]]++;
        }

        vector<int> ans;
        for (auto i : mp)
        {
            if (i.second == 1 && mp.find(i.first + 1) == mp.end() && mp.find(i.first - 1) == mp.end())
            {
                ans.push_back(i.first);
            }
        }
        return ans;
    }
};