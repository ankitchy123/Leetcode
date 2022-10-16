class Solution
{
public:
    vector<int> numberOfPairs(vector<int> &nums)
    {
        map<int, int> mp;
        for (int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]]++;
        }

        vector<int> ans(2, 0);
        for (auto i : mp)
        {
            if (i.second % 2 == 0)
            {
                ans[0] += i.second / 2;
                mp.erase(i.first);
            }
            else
            {
                ans[0] += i.second / 2;
                i.second = 1;
                ans[1]++;
                mp.erase(i.first);
            }
        }
        return ans;
    }
};