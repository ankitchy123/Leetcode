class Solution
{
public:
    bool possible(vector<int> weights, int days, int cap)
    {
        int curr = 0, temp = 1;
        for (int weight : weights)
        {
            curr += weight;
            if (curr > cap)
            {
                temp++;
                curr = weight;
            }
        }
        return temp <= days;
    }
    int shipWithinDays(vector<int> &weights, int days)
    {
        int e = 0, s = 0;
        for (int weight : weights)
        {
            e += weight;
            s = max(s, weight);
        }

        while (s < e)
        {
            int mid = s + (e - s) / 2;
            if (possible(weights, days, mid))
            {
                e = mid;
            }
            else
            {
                s = mid + 1;
            }
        }
        return e;
    }
};