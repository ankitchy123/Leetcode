class Solution
{
public:
    int minOperations(vector<int> &nums)
    {
        int ans = 0, count = 0;
        while (count != nums.size())
        {
            count = 0;
            for (int i = 0; i < nums.size(); i++)
            {
                if (nums[i] % 2 == 1)
                {
                    nums[i] -= 1;
                    ans++;
                }

                if (nums[i] != 0)
                {
                    nums[i] /= 2;
                }
                else
                {
                    count++;
                }
            }
            if (count != nums.size())
            {
                ans++;
            }
        }
        return ans;
    }
};