class Node
{
public:
    Node *prev;
    string val;
    Node *next;

};
class BrowserHistory
{
public:
    Node *Head, *Cur;
    BrowserHistory(string homepage)
    {
        Head = new Node;
        Head->next = NULL;
        Head->prev = NULL;
        Head->val = homepage;
        Cur = Head;
    }

    void visit(string url)
    {
        if(Cur->next)
        {
            Cur = Cur->next;
            Cur->val = url;
            Cur->next = NULL;
            if(Cur->next)
            {
                Node *t = Cur->next, *q = NULL;
                while(t)
                {
                    if(t) q = t->next;
                    delete t;
                    t = q;
                }
            }
        }
        else
        {
            Node *t = Cur;
            Cur->next = new Node;
            Cur = Cur->next;
            Cur->val = url;
            Cur->next = NULL;
            Cur->prev = t;
        }
    }

    string back(int steps)
    {
        while(steps--)
        {
            if(Cur->prev) Cur = Cur->prev;
            else break;
        }
        return Cur->val;
    }

    string forward(int steps)
    {
        while(steps--)
        {
            if(Cur->next) Cur = Cur->next;
            else break;
        }
        return Cur->val;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
