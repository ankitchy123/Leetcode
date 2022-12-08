class Node
{
public:
    char data;
    Node *next;
    Node *prev;

    Node(char data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};
class TextEditor
{
public:
    Node *head;
    TextEditor()
    {
        head = new Node('|');
    }

    void addText(string text)
    {
        for (int i = 0; i < text.size(); i++)
        {
            Node *newNode = new Node(text[i]);
            Node *prevNode = head->prev;

            if (prevNode)
            {
                prevNode->next = newNode;
            }
            newNode->prev = prevNode;
            newNode->next = head;
            head->prev = newNode;
        }
    }

    int deleteText(int k)
    {
        int count = 0;
        while (count < k && head->prev)
        {
            Node *prevNode = head->prev->prev;
            delete head->prev;

            if (prevNode)
            {
                prevNode->next = head;
            }
            head->prev = prevNode;
            count++;
        }
        return count;
    }

    string cursorLeft(int k)
    {
        while (k-- && head->prev)
        {
            Node *temp = head->prev->prev;
            Node *temp2 = head->prev;
            if (head->next)
            {
                head->next->prev = temp2;
            }
            temp2->next = head->next;
            if (temp)
            {
                temp->next = head;
            }
            head->prev = temp;
            head->next = temp2;
            temp2->prev = head;
        }

        string s = "";
        int n = 10;
        Node *temp = head->prev;
        while (n-- && temp)
        {
            s += temp->data;
            temp = temp->prev;
        }
        reverse(s.begin(), s.end());
        return s;
    }

    string cursorRight(int k)
    {
        while (k-- && head->next)
        {
            Node *temp = head->next->next;
            Node *temp2 = head->next;
            if (temp)
            {
                temp->prev = head;
            }
            head->next = temp;
            temp2->prev = head->prev;
            temp2->next = head;
            head->prev = temp2;
        }

        string s = "";
        int n = 10;
        Node *temp = head->prev;
        while (n-- && temp)
        {
            s += temp->data;
            temp = temp->prev;
        }
        reverse(s.begin(), s.end());
        return s;
    }
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */