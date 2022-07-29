class Solution
{
public:
    int calPoints(vector<string> &ops)
    {
        vector<int> vec;
        for (int i = 0; i < ops.size(); i++)
        {
            if (ops[i] == "+")
            {
                int n = vec.size() - 1;
                int temp = vec[n] + vec[n - 1];
                vec.push_back(temp);
            }
            else if (ops[i] == "C")
            {
                vec.pop_back();
            }
            else if (ops[i] == "D")
            {
                int temp = vec[vec.size() - 1] * 2;
                vec.push_back(temp);
            }
            else
            {
                vec.push_back(stoi(ops[i]));
            }
        }

        int sum = 0;
        for (int i = 0; i < vec.size(); i++)
        {
            sum += vec[i];
        }

        return sum;
    }
};