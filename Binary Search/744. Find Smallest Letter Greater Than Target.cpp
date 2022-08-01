class Solution
{
public:
    char nextGreatestLetter(vector<char> &letters, char target)
    {
        int i = 0, j = letters.size() - 1;
        int ans = 0;

        if (target >= letters[letters.size() - 1])
        {
            return letters[0];
        }

        while (i <= j)
        {
            int mid = (i + j) / 2;

            if (letters[mid] == target)
            {
                ans = max(mid, ans);
                i = mid + 1;
            }
            else if (letters[mid] > target)
            {
                ans = mid;
                j = mid - 1;
            }
            else
            {
                i = mid + 1;
            }
        }

        return letters[ans];
    }
};