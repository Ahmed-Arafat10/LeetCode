class Node
{
public:
    Node *prev;
    char val;
    Node *next;
};

class TextEditor
{
public:
    Node *Cursor;
    TextEditor()
    {
        Cursor = new Node;
        Cursor->val = '|';
        Cursor->next = NULL;
        Cursor->prev = NULL;
    }

    void addText(string text)
    {
        Node *connect = Cursor->prev;
        Node *t = Cursor;
        for(int i =text.size()-1; i>=0; i--)
        {

            t->prev = new Node;
            Node *tt = t;
            t = t->prev;
            t->val = text[i];
            t->next = tt;
            t->prev = NULL;
        }
        t->prev = connect;
        if(connect) connect->next = t;
    }

    int deleteText(int k)
    {
        int cnt = 0;
        Node *p = Cursor->prev;
        while(k-- && p)
        {
            cnt++;
            p = p->prev;
        }
        // cout<<p->val<<"--HERE\n";
        if(p) p->next = Cursor;
        Cursor->prev = p;
        return cnt;
    }

    string cursorLeft(int k)
    {
        Node *t = Cursor;
        int k1 = 10;
        while(k-- && t->prev)
        {
            t = t->prev;
        }  /// leetpractice|
        if(Cursor != t)
        {
            if(Cursor->next) Cursor->next->prev = Cursor->prev;
            if(Cursor->prev) Cursor->prev->next = Cursor->next;
            Cursor->next = t;
            Cursor->prev = t->prev;
        }
        string temp ;
        t = Cursor->prev;
        while(k1-- && t)
        {
            temp += t->val;
            t = t->prev;
        }
        reverse(temp.begin(),temp.end());
        return temp;
    }

    string cursorRight(int k)
    {
        Node *t = Cursor;
        int k1 = 10;
        while(k-- && t->next)
        {
            t = t->next;
        } //pra|ctice
        if(Cursor != t)
        {
            if(Cursor->next) Cursor->next->prev = Cursor->prev;
            if(Cursor->prev) Cursor->prev->next = Cursor->next;
            Cursor->next = t->next;
            Cursor->prev = t;
        }
        string temp ;
        t = Cursor->prev;
        //cout<<t->val;
        while(k1-- && t)
        {

            temp += t->val;
            t = t->prev;
        }
        reverse(temp.begin(),temp.end());
        return temp;
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
