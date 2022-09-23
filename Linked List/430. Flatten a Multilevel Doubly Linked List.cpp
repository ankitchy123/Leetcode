/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution
{
public:
    Node *flatten(Node *head)
    {
        Node *temp = head;
        while (temp)
        {
            Node *newTemp = temp->next;
            if (temp->child)
            {
                Node *child = temp->child;
                temp->child = NULL;
                child->prev = temp;
                temp->next = child;
                Node *temp2 = child;

                temp2 = flatten(temp2);
                while (temp2->next)
                {
                    temp2 = temp2->next;
                }
                temp2->next = newTemp;
                if (newTemp)
                {
                    newTemp->prev = temp2;
                }
            }
            temp = newTemp;
        }
        return head;
    }
};