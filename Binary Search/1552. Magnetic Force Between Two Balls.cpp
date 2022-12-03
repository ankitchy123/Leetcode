class Solution
{
public:
    bool check(vector<int> &position, int m, int mid)
    {
        int count = 1, prev = position[0];
        for (int i = 1; i < position.size(); i++)
        {
            if (position[i] - prev >= mid)
            {
                count++;
                prev = position[i];
            }
        }
        if (count >= m)
        {
            return true;
        }
        return false;
    }
    int maxDistance(vector<int> &position, int m)
    {
        sort(position.begin(), position.end());
        int low = 1, high = position[position.size() - 1] - position[0];
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (check(position, m, mid))
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return high;
    }
};