class Solution
{
public:
    vector<bool> prefixesDivBy5(vector<int> &nums)
    {
        vector<bool> ans;
        int n;
        for (int i = 0; i < nums.size(); i++)
        {
            n = (n * 2 + nums[i]) % 5;
            if (n == 0)
            {
                ans.push_back(true);
            }
            else
            {
                ans.push_back(false);
            }
        }

        return ans;
    }
};