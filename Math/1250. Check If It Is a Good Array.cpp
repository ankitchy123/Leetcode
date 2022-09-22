class Solution
{
public:
    bool isGoodArray(vector<int> &nums)
    {
        int num = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            num = __gcd(num, nums[i]);
        }

        if (num == 1)
        {
            return true;
        }
        return false;
    }
};