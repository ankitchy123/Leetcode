class Solution
{
public:
    void reverse(string &s, int low, int high)
    {
        while (low < high)
        {
            swap(s[low], s[high]);
            low++;
            high--;
        }
    }

    string reverseWords(string s)
    {
        int start = 0;

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == ' ')
            {
                reverse(s, start, i - 1);
                start = i + 1;
            }
        }
        reverse(s, start, s.size() - 1);

        return s;
    }
};