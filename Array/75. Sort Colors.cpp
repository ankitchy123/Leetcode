class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        vector<int> vec(3, 0);

        for (int i = 0; i < nums.size(); i++)
        {
            vec[nums[i]]++;
        }

        int j = 0;
        for (int i = 0; i < 3; i++)
        {
            int temp = vec[i];
            while (temp)
            {
                nums[j] = i;
                j++;
                temp--;
            }
        }
    }
};

// OR

class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int count0 = 0, count1 = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
            {
                swap(nums[i], nums[count0 + count1]);
                swap(nums[count0 + count1], nums[count0]);
                count0++;
            }
            else if (nums[i] == 1)
            {
                swap(nums[i], nums[count0 + count1]);
                count1++;
            }
        }
    }
};