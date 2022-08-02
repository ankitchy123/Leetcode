class Solution
{
public:
    vector<int> numberOfLines(vector<int> &widths, string s)
    {
        int count = 0;
        int i = 0;
        int lines = 1;
        while (i < s.size())
        {
            int j = s[i] - 97;
            count += widths[j];
            if (count > 100)
            {
                count = widths[j];
                lines++;
            }
            i++;
        }

        vector<int> vec;
        vec.push_back(lines);
        vec.push_back(count);

        return vec;
    }
};