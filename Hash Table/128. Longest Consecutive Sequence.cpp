class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        set<int> s;
        for (int i = 0; i < nums.size(); i++)
        {
            s.insert(nums[i]);
        }

        int ans = 0;
        for (auto i : s)
        {
            if (s.find(i - 1) == s.end())
            {
                int num = i;
                int curr = 1;
                while (s.find(num + 1) != s.end())
                {
                    curr++;
                    num++;
                }
                ans = max(ans, curr);
            }
        }
        return ans;
    }
};