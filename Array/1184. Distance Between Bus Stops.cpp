class Solution
{
public:
    int distanceBetweenBusStops(vector<int> &distance, int start, int destination)
    {
        int d1 = 0, d2 = 0;
        int i = start;
        while (i != destination)
        {
            d1 += distance[i];
            i = (i + 1) % distance.size();
        }
        while (i != start)
        {
            d2 += distance[i];
            i = (i + 1) % distance.size();
        }
        return min(d1, d2);
    }
};