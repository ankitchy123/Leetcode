class Solution
{
public:
    bool checkIfCanBreak(string s1, string s2)
    {
        vector<int> vec1(26, 0), vec2(26, 0);
        for (int i = 0; i < s1.size(); i++)
        {
            vec1[s1[i] - 'a']++;
            vec2[s2[i] - 'a']++;
        }
        bool flag1 = true, flag2 = true;
        int cnt1 = 0, cnt2 = 0;

        for (int i = 0; i < 26; i++)
        {
            cnt1 += vec1[i] - vec2[i];
            cnt2 += vec2[i] - vec1[i];
            if (cnt1 < 0)
            {
                flag1 = false;
            }
            if (cnt2 < 0)
            {
                flag2 = false;
            }
        }
        return flag1 || flag2;
    }
};