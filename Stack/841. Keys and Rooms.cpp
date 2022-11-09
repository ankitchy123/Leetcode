class Solution
{
public:
    bool canVisitAllRooms(vector<vector<int>> &rooms)
    {
        vector<bool> isVisited(rooms.size(), false);
        isVisited[0] = true;

        stack<int> st;
        st.push(0);

        while (!st.empty())
        {
            int ind = st.top();
            st.pop();
            for (int i = 0; i < rooms[ind].size(); i++)
            {
                if (!isVisited[rooms[ind][i]])
                {
                    isVisited[rooms[ind][i]] = true;
                    st.push(rooms[ind][i]);
                }
            }
        }

        for (int i = 0; i < isVisited.size(); i++)
        {
            if (!isVisited[i])
            {
                return false;
            }
        }
        return true;
    }
};