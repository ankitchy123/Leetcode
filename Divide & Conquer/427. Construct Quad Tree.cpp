/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution
{
public:
    Node *solve(vector<vector<int>> &grid, int rowStart, int rowEnd, int colStart, int colEnd)
    {
        if (rowStart > rowEnd || colStart > colEnd)
        {
            return NULL;
        }

        bool isLeaf = true;
        int val = grid[rowStart][colStart];
        for (int i = rowStart; i <= rowEnd; i++)
        {
            for (int j = colStart; j <= colEnd; j++)
            {
                if (grid[i][j] != val)
                {
                    isLeaf = false;
                    break;
                }
            }
            if (!isLeaf)
            {
                break;
            }
        }
        if (isLeaf)
        {
            return new Node(val, 1);
        }

        int rowMid = rowStart + (rowEnd - rowStart) / 2;
        int colMid = colStart + (colEnd - colStart) / 2;
        Node *topLeft = solve(grid, rowStart, rowMid, colStart, colMid);
        Node *topRight = solve(grid, rowStart, rowMid, colMid + 1, colEnd);
        Node *bottomLeft = solve(grid, rowMid + 1, rowEnd, colStart, colMid);
        Node *bottomRight = solve(grid, rowMid + 1, rowEnd, colMid + 1, colEnd);

        return new Node(0, 0, topLeft, topRight, bottomLeft, bottomRight);
    }
    Node *construct(vector<vector<int>> &grid)
    {
        int n = grid.size();
        return solve(grid, 0, n - 1, 0, n - 1);
    }
};