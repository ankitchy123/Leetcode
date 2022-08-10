class Solution
{
public:
    int largestSumAfterKNegations(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        int i = 0;
        while (nums[i] < 0 && i < nums.size())
        {
            if (k <= 0)
            {
                break;
            }
            nums[i] = -nums[i];
            i++;
            k--;
        }
        sort(nums.begin(), nums.end());
        i = 0;
        while (k)
        {
            nums[i] = -nums[i];
            k--;
        }

        int ans = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            ans += nums[i];
        }
        return ans;
    }
};