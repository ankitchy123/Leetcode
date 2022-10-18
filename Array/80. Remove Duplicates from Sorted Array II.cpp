class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int count = 1, k = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i - 1] == nums[i])
            {
                if (count < 2)
                {
                    nums[k] = nums[i];
                    k++;
                    count++;
                }
            }
            else
            {
                count = 1;
                nums[k] = nums[i];
                k++;
            }
        }
        return k;
    }
};