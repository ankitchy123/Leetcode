class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int count = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (count < i)
            {
                return false;
            }
            count = max(count, i + nums[i]);
        }
        return true;
    }
};