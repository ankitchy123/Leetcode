class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int ans = 0, end = 0, next = 0;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            next = max(next, i + nums[i]);
            if (i == end)
            {
                ans++;
                end = next;
            }
        }
        return ans;
    }
};