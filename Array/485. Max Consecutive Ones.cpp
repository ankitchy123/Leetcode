class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        int curr = 0, ans = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
            {
                ans = max(ans, curr);
                curr = 0;
                continue;
            }
            curr++;
        }
        ans = max(ans, curr);
        return ans;
    }
};