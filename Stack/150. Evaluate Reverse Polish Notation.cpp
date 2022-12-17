class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<long long> st;
        for (int i = 0; i < tokens.size(); i++)
        {
            if (tokens[i] == "+" || tokens[i] == "*" || tokens[i] == "/" || tokens[i] == "-")
            {
                long long num1 = st.top();
                st.pop();
                long long num2 = st.top();
                st.pop();
                long long num;
                if (tokens[i] == "+")
                {
                    num = num2 + num1;
                }
                else if (tokens[i] == "-")
                {
                    num = num2 - num1;
                }
                else if (tokens[i] == "*")
                {
                    num = num2 * num1;
                }
                else
                {
                    num = num2 / num1;
                }
                st.push(num);
                cout << num << " ";
            }
            else
            {
                long long temp = stoi(tokens[i]);
                st.push(temp);
            }
        }
        return st.top();
    }
};