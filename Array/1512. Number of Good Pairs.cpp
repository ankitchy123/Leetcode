class Solution
{
public:
    int numIdenticalPairs(vector<int> &nums)
    {
        int ans = 0;
        sort(nums.begin(), nums.end());
        int n = nums.size();

        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (nums[i] == nums[j])
                {
                    ans += 1;
                }
                else
                {
                    break;
                }
            }
        }

        return ans;
    }
};