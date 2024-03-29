class Solution
{
public:
    int minMoves(int target, int maxDoubles)
    {
        int ans = 0;
        while (target != 1)
        {
            if (maxDoubles == 0)
            {
                return ans + target - 1;
            }

            ans++;
            if (target % 2 == 0)
            {
                target /= 2;
                maxDoubles--;
            }
            else
            {
                target--;
            }
        }
        return ans;
    }
};