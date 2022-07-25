class Solution
{
public:
    int sum(int n)
    {
        int sum = 0;
        while (n)
        {
            int num = n % 10;
            sum += num * num;
            n /= 10;
        }
        return sum;
    }
    // In this problem, we use set because set does not contain duplicate value...... So if any duplicate value appear then it go to the infinite loop then we return Not Happy i.e false

    bool isHappy(int n)
    {
        set<int> st;

        while (1)
        {
            n = sum(n);
            if (n == 1)
            {
                return true;
            }
            // Searches the container for an element equivalent to val and returns an iterator to it if found, otherwise it returns an iterator to set::end.
            else if (st.find(n) != st.end())
            {
                return false;
            }

            st.insert(n);
        }

        return false;
    }
};