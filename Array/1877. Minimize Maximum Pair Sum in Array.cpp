class Solution
{
public:
    int minPairSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int curr = INT_MIN, ans = INT_MIN;
        for (int i = 0; i < nums.size() / 2; i++)
        {
            curr = nums[i] + nums[nums.size() - 1 - i];
            ans = max(ans, curr);
        }
        return ans;
    }
};