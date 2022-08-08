class Solution
{
public:
    vector<int> minOperations(string boxes)
    {
        int n = boxes.size();
        int sum = 0, left = 0, right = 0;
        for (int i = 0; i < n; i++)
        {
            if (boxes[i] == '1')
            {
                sum += i;
                right++;
            }
        }

        vector<int> vec(n);
        for (int i = 0; i < n; i++)
        {
            vec[i] = sum;
            if (boxes[i] == '1')
            {
                left++;
                right--;
            }
            sum += left - right;
        }
        return vec;
    }
};