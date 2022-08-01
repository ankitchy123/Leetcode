class Solution
{
public:
    int pivotIndex(vector<int> &nums)
    {
        int total = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            total += nums[i];
        }

        int sum = 0;
        int i = 0;
        while (i < nums.size())
        {
            if (total - nums[i] - sum == sum)
            {
                return i++;
            }
            sum += nums[i];
            i++;
        }
        return -1;
    }
};