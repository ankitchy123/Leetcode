class Solution
{
public:
    int sumOddLengthSubarrays(vector<int> &arr)
    {
        int sum = 0;

        for (int i = 0; i < arr.size(); i++)
        {
            int currSum = 0;
            int count = 1;
            for (int j = i; j < arr.size(); j++)
            {
                currSum += arr[j];
                if (count % 2 == 1)
                {
                    sum += currSum;
                }
                count++;
            }
        }

        return sum;
    }
};