class Solution
{
public:
    double angleClock(int hour, int minutes)
    {
        hour %= 12;
        double h = double(hour + (minutes / 60.0)) * 30;
        double m = 6 * minutes;

        double ans = abs(m - h);

        return min(ans, 360 - ans);
    }
};