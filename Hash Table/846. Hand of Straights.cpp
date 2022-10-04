class Solution
{
public:
    bool isNStraightHand(vector<int> &hand, int groupSize)
    {
        map<int, int> mp;
        for (int i = 0; i < hand.size(); i++)
        {
            mp[hand[i]]++;
        }
        for (auto m : mp)
        {
            if (m.second <= 0)
            {
                continue;
            }

            int curr = m.first;
            int temp = m.second;

            for (int i = 1; i < groupSize; i++)
            {
                if (mp.find(curr + 1) != mp.end() && mp[curr + i] - temp >= 0)
                {
                    mp[curr + i] -= temp;
                }
                else
                {
                    return false;
                }
            }
        }
        return true;
    }
};