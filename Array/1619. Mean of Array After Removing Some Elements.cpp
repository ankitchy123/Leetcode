class Solution
{
public:
    double trimMean(vector<int> &arr)
    {
        int num = arr.size() / 20;
        sort(arr.begin(), arr.end());

        int count = arr.size() - (2 * num);

        double sum = 0.0;
        for (int i = num; i < arr.size() - num; i++)
        {
            sum += arr[i];
        }
        return sum / count;
    }
};