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
        int low = 0, high = nums.size() - 1;

        int mid = 0;
        while (mid <= high)
        {
            if (nums[mid] == 0)
            {
                swap(nums[mid], nums[low]);
                low++;
                mid++;
            }
            else if (nums[mid] == 2)
            {
                swap(nums[mid], nums[high]);
                high--;
            }
            else
            {
                mid++;
            }
        }
    }
};