class Solution
{
public:
    vector<int> executeInstructions(int n, vector<int> &startPos, string s)
    {
        vector<int> ans;
        int x = startPos[0], y = startPos[1];
        int count = 0;
        for (int i = 0; i < s.size(); i++)
        {
            x = startPos[0];
            y = startPos[1];
            count = 0;
            for (int j = i; j < s.size(); j++)
            {
                if (s[j] == 'L')
                {
                    y--;
                }
                else if (s[j] == 'R')
                {
                    y++;
                }
                else if (s[j] == 'U')
                {
                    x--;
                }
                else if (s[j] == 'D')
                {
                    x++;
                }

                if (x >= 0 && x < n && y >= 0 && y < n)
                {
                    count++;
                }
                else
                {
                    break;
                }
            }
            ans.push_back(count);
        }
        return ans;
    }
};