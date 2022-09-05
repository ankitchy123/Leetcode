/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution
{
public:
    vector<vector<int>> levelOrder(Node *root)
    {
        if (!root)
        {
            return {};
        }
        queue<Node *> q;
        q.push(root);
        q.push(NULL);
        vector<vector<int>> ans;
        vector<int> vec;

        while (!q.empty())
        {
            Node *temp = q.front();
            q.pop();

            if (temp)
            {
                vec.push_back(temp->val);
                int i = 0;
                while (i < temp->children.size())
                {
                    q.push(temp->children[i]);
                    i++;
                }
            }

            else if (!q.empty())
            {
                q.push(NULL);
                ans.push_back(vec);
                vec.clear();
            }
        }
        ans.push_back(vec);
        return ans;
    }
};