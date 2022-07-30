class Solution
{
public:
    int dominantIndex(vector<int> &nums)
    {
        int j = -1;
        int num = INT_MIN;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > num)
            {
                j = i;
                num = nums[i];
            }
        }

        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 1; i++)
        {
            nums[i] *= 2;

            if (nums[nums.size() - 1] < nums[i])
            {
                return -1;
            }
        }
        return j;
    }
};