class Solution
{
public:
    string discountPrices(string sentence, int discount)
    {
        string word = "";
        vector<string> vec;
        for (int i = 0; i < sentence.size(); i++)
        {
            if (sentence[i] == ' ')
            {
                vec.push_back(word);
                word = "";
            }
            else
            {
                word += sentence[i];
            }
        }
        vec.push_back(word);

        for (int i = 0; i < vec.size(); i++)
        {
            bool found = false;
            string temp = "";
            for (int j = 0; j < vec[i].size(); j++)
            {
                if (j == 0 && vec[i][j] == '$')
                {
                    found = true;
                }
                else if (found == true)
                {
                    if (vec[i][j] >= '0' && vec[i][j] <= '9')
                    {
                        temp += vec[i][j];
                    }
                    else
                    {
                        found = false;
                        break;
                    }
                }
            }
            if (found && temp.size() > 0)
            {
                long long num = stoll(temp);
                long double discountPrice = (num * discount) / 100.0;
                long double finalNum = num - discountPrice;
                vec[i] = "$";
                vec[i] += to_string(finalNum);
                int temp = 4;
                while (temp--)
                {
                    vec[i].pop_back();
                }
            }
        }
        string ans = "";
        for (int i = 0; i < vec.size(); i++)
        {
            ans += vec[i] + " ";
        }
        ans.pop_back();
        return ans;
    }
};