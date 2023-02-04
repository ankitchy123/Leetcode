class Solution
{
public:
    bool isEqual(vector<int> vec1, vector<int> vec2)
    {
        for (int i = 0; i < 26; i++)
        {
            if (vec1[i] != vec2[i])
            {
                return false;
            }
        }
        return true;
    }
    bool checkInclusion(string s1, string s2)
    {
        if (s1.size() > s2.size())
        {
            return false;
        }
        vector<int> vec1(26, 0), vec2(26, 0);
        for (int i = 0; i < s1.size(); i++)
        {
            vec1[s1[i] - 'a']++;
            vec2[s2[i] - 'a']++;
        }

        int count = 0;
        for (int i = 0; i < 26; i++)
        {
            if (vec1[i] == vec2[i])
            {
                count++;
            }
        }

        for (int i = 0; i < s2.size() - s1.size(); i++)
        {
            if (count == 26)
            {
                return true;
            }
            vec2[s2[i + s1.size()] - 'a']++;
            if (vec2[s2[i + s1.size()] - 'a'] == vec1[s2[i + s1.size()] - 'a'])
            {
                count++;
            }
            else if (vec2[s2[i + s1.size()] - 'a'] == vec1[s2[i + s1.size()] - 'a'] + 1)
            {
                count--;
            }

            vec2[s2[i] - 'a']--;
            if (vec2[s2[i] - 'a'] == vec1[s2[i] - 'a'])
            {
                count++;
            }
            else if (vec2[s2[i] - 'a'] == vec1[s2[i] - 'a'] - 1)
            {
                count--;
            }
        }
        return count == 26;
    }
};