class Solution
{
public:
    int arithmeticTriplets(vector<int> &nums, int diff)
    {
        map<int, int> mp;
        int ans = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]] = 0;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (mp.find(nums[i] - diff) != mp.end())
            {
                if (mp.find(nums[i] + diff) != mp.end())
                {
                    mp[nums[i] + diff]++;
                }
            }
            ans += mp[nums[i]];
        }

        return ans;
    }
};