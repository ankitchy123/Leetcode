class Solution
{
public:
    string addStrings(string num1, string num2)
    {
        int i = 0, j = 0;
        int carry = 0;
        string ans = "";
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        while (i < num1.size() && j < num2.size())
        {
            int sum = num1[i] - '0' + num2[j] - '0' + carry;
            ans += sum % 10 + '0';
            carry = sum / 10;
            i++;
            j++;
        }

        while (i < num1.size())
        {
            int sum = num1[i] - '0' + carry;
            ans += sum % 10 + '0';
            carry = sum / 10;
            i++;
        }
        while (j < num2.size())
        {
            int sum = num2[j] - '0' + carry;
            ans += sum % 10 + '0';
            carry = sum / 10;
            j++;
        }

        if (carry)
            ans += carry + '0';
        reverse(ans.begin(), ans.end());
        return ans;
    }
};