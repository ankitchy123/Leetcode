class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            while (nums[i] >= 1 && nums[i] <= n && nums[i] != nums[nums[i] - 1])
            {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }

        int j = 1;
        for (j = 1; j <= n; j++)
        {
            if (nums[j - 1] != j)
            {
                break;
            }
        }

        return j;
    }
};