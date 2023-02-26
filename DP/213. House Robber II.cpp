class Solution
{
public:
    int rob(vector<int> &nums)
    {
        if (nums.size() == 1)
        {
            return nums[0];
        }
        int prev = nums[0], prev2 = 0;
        for (int i = 1; i < nums.size() - 1; i++)
        {
            int temp = max(prev2 + nums[i], prev);
            prev2 = prev;
            prev = temp;
        }
        int ans1 = prev;

        prev = nums[1], prev2 = 0;
        for (int i = 2; i < nums.size(); i++)
        {
            int temp = max(prev2 + nums[i], prev);
            prev2 = prev;
            prev = temp;
        }
        int ans2 = prev;
        return max(ans1, ans2);
    }
};