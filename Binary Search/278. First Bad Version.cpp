// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution
{
public:
    int firstBadVersion(int n)
    {
        int ans;

        long int s = 1, e = n;

        while (s <= e)
        {
            int mid = (s + e) / 2;
            if (isBadVersion(mid))
            {
                e = mid - 1;
                ans = mid;
            }
            else
            {
                s = mid + 1;
            }
        }
        return ans;
    }
};