class Solution
{
public:
    int numUniqueEmails(vector<string> &emails)
    {
        set<string> st;
        for (int i = 0; i < emails.size(); i++)
        {
            string str = "";
            for (int j = 0; j < emails[i].size(); j++)
            {
                if (emails[i][j] == '.')
                {
                    continue;
                }
                else if (emails[i][j] == '@' || emails[i][j] == '+')
                {
                    break;
                }

                str += emails[i][j];
            }
            str += emails[i].substr(emails[i].find('@'));
            st.insert(str);
        }

        return st.size();
    }
};