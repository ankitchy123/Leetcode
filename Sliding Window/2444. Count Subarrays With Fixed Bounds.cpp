class Solution
{
public:
    long long countSubarrays(vector<int> &nums, int minK, int maxK)
    {
        int m = -1, n = -1, left = 0;
        long long ans = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] < minK || nums[i] > maxK)
            {
                left = i + 1;
                m = -1;
                n = -1;
            }
            else
            {
                if (nums[i] == minK)
                {
                    m = i;
                }
                if (nums[i] == maxK)
                {
                    n = i;
                }
                ans += max(0, min(m, n) - left + 1);
            }
        }
        return ans;
    }
};