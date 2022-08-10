class Solution
{
public:
    int repeatedNTimes(vector<int> &nums)
    {
        int count = 0;
        int temp = 1, ans;
        sort(nums.begin(), nums.end());
        // 1 2 2 2 3 5
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] == nums[i - 1])
            {
                temp++;
            }
            else
            {
                if (temp > count)
                {
                    count = temp;
                    ans = nums[i - 1];
                }
                temp = 1;
            }
        }
        if (temp > count)
        {
            count = temp;
            ans = nums[nums.size() - 1];
        }

        return ans;
    }
};