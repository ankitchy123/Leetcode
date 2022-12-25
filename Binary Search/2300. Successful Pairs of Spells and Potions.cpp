class Solution
{
public:
    vector<int> successfulPairs(vector<int> &spells, vector<int> &potions, long long success)
    {
        sort(potions.begin(), potions.end());

        for (int i = 0; i < spells.size(); i++)
        {
            int s = 0, e = potions.size() - 1;
            while (s <= e)
            {
                int mid = s + (e - s) / 2;
                long long m = (long long)spells[i] * potions[mid];
                if (m >= success)
                {
                    e = mid - 1;
                }
                else
                {
                    s = mid + 1;
                }
            }
            spells[i] = potions.size() - s;
        }
        return spells;
    }
};