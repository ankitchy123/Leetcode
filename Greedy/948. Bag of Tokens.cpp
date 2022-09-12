class Solution
{
public:
    int bagOfTokensScore(vector<int> &tokens, int power)
    {
        sort(tokens.begin(), tokens.end());

        int l = 0, h = tokens.size() - 1;
        int ans = 0;
        while (l <= h)
        {
            if (tokens[l] <= power)
            {
                ans++;
                power -= tokens[l++];
            }
            else if (ans >= 1 && l < h)
            {
                ans--;
                power += tokens[h--];
            }
            else
                break;
        }
        return ans;
    }
};