class Solution
{
public:
    int maximumTop(vector<int> &nums, int k)
    {
        int n = nums.size();
        if (k == 1)
        {
            if (n == 1)
            {
                return -1;
            }
            return nums[1];
        }
        if (n == 1 && k % 2 != 0)
        {
            return -1;
        }
        int temp = INT_MIN, i = 0;
        for (i = 0; i < min(k - 1, n); i++)
        {
            temp = max(temp, nums[i]);
        }
        if (k < n)
        {
            temp = max(temp, nums[k]);
        }
        return temp;
    }
};