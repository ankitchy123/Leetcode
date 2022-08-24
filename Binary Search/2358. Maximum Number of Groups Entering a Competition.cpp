class Solution
{
public:
    int maximumGroups(vector<int> &grades)
    {
        int s = 1, e = grades.size();
        int count = 0;
        long long int n = grades.size();
        while (s <= e)
        {
            long long int mid = s + (e - s) / 2;
            long long int x = (mid * (mid + 1)) / 2;
            if (x <= grades.size())
            {
                count = mid;
                s = mid + 1;
            }
            else
            {
                e = mid - 1;
            }
        }
        return count;
    }
};