class Solution
{
public:
    int garbageCollection(vector<string> &garbage, vector<int> &travel)
    {
        int x = 0, y = 0, z = 0;
        for (int i = garbage.size() - 1; i >= 0; i--)
        {
            string s = garbage[i];
            int n1 = 0, n2 = 0, n3 = 0;
            for (int j = 0; j < s.size(); j++)
            {
                if (s[j] == 'M')
                {
                    n1++;
                }
                else if (s[j] == 'P')
                {
                    n2++;
                }
                else
                {
                    n3++;
                }
            }
            x += n1;
            y += n2;
            z += n3;
            if (i == 0)
            {
                break;
            }
            if (x > 0)
            {
                x += travel[i - 1];
            }
            if (y > 0)
            {
                y += travel[i - 1];
            }
            if (z > 0)
            {
                z += travel[i - 1];
            }
        }
        return x + y + z;
    }
};