class Solution
{
public:
    bool asteroidsDestroyed(int mass, vector<int> &asteroids)
    {
        sort(asteroids.begin(), asteroids.end());

        int max = 100000;
        for (int i = 0; i < asteroids.size(); i++)
        {
            if (mass < asteroids[i])
            {
                return false;
            }
            if (mass + asteroids[i] > max)
            {
                return true;
            }
            mass += asteroids[i];
        }
        return true;
    }
};