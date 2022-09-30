class Solution
{
public:
    int maximumBags(vector<int> &capacity, vector<int> &rocks, int additionalRocks)
    {
        vector<int> vec(rocks.size(), -1);

        for (int i = 0; i < rocks.size(); i++)
        {
            vec[i] = capacity[i] - rocks[i];
        }

        sort(vec.begin(), vec.end());
        int i = 0;

        while (i < vec.size() && additionalRocks - vec[i] >= 0)
        {
            additionalRocks = additionalRocks - vec[i];
            i++;
        }

        return i;
    }
};