class Solution
{
public:
    int countGoodRectangles(vector<vector<int>> &rectangles)
    {
        int count = 0;
        for (int i = 0; i < rectangles.size(); i++)
        {
            int n = min(rectangles[i][0], rectangles[i][1]);
            if (n > count)
            {
                count = n;
            }
        }

        int ans = 0;
        for (int i = 0; i < rectangles.size(); i++)
        {
            int n = min(rectangles[i][0], rectangles[i][1]);
            if (n == count)
            {
                ans++;
            }
        }
        return ans;
    }
};