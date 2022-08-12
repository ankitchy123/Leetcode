class Solution
{
public:
    bool canThreePartsEqualSum(vector<int> &arr)
    {
        int total = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            total += arr[i];
        }
        if (total % 3 != 0)
        {
            return false;
        }

        int target = total / 3;
        int sum = 0, count = 0;

        for (int i = 0; i < arr.size(); i++)
        {
            sum += arr[i];
            if (sum == target)
            {
                sum = 0;
                count++;
            }
        }

        if (count >= 3)
        {
            return true;
        }
        return false;
    }
};