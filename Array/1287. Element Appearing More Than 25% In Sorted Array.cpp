class Solution
{
public:
    int findSpecialInteger(vector<int> &arr)
    {
        int n = arr.size() / 4;
        int count = 1;
        for (int i = 1; i < arr.size(); i++)
        {
            if (arr[i - 1] != arr[i])
            {
                if (count > n)
                {
                    return arr[i - 1];
                }
                count = 1;
                continue;
            }
            count++;
        }
        if (count > n)
        {
            return arr[arr.size() - 1];
        }

        return -1;
    }
};