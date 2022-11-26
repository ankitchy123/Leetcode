/*
 * // This is the custom function interface.
 * // You should not implement it, or speculate about its implementation
 * class CustomFunction {
 * public:
 *     // Returns f(x, y) for any given positive integers x and y.
 *     // Note that f(x, y) is increasing with respect to both x and y.
 *     // i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
 *     int f(int x, int y);
 * };
 */

class Solution
{
public:
    vector<vector<int>> findSolution(CustomFunction &func, int z)
    {
        vector<vector<int>> ans;
        int l = 1, h = 1000;
        while (l <= 1000 && h >= 1)
        {
            if (func.f(l, h) == z)
            {
                ans.push_back({l, h});
                l++;
            }
            else if (func.f(l, h) < z)
            {
                l++;
            }
            else
            {
                h--;
            }
        }
        return ans;
    }
};