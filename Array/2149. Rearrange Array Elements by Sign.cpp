class Solution
{
public:
    vector<int> rearrangeArray(vector<int> &nums)
    {
        vector<int> vec(nums.size(), 0);
        int i = 0, j = 1;
        for (int k = 0; k < nums.size(); k++)
        {
            if (nums[k] > 0)
            {
                vec[i] = nums[k];
                i += 2;
            }
            else
            {
                vec[j] = nums[k];
                j += 2;
            }
        }

        return vec;
    }
};