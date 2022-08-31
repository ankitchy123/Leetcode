class Solution
{
public:
    int wateringPlants(vector<int> &plants, int capacity)
    {
        int temp = capacity;
        int steps = 0;
        for (int i = 0; i < plants.size(); i++)
        {
            if (plants[i] > temp)
            {
                steps += 2 * (i + 1) - 1;
                temp = capacity - plants[i];
            }
            else
            {
                temp -= plants[i];
                steps++;
            }
        }
        return steps;
    }
};