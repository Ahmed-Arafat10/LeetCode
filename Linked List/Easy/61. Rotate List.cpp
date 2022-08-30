/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int cnt(ListNode *p)
{
    int cnt = 0;
    while(p !=NULL)
    {
        cnt++;
        p=p->next;
    }
    return cnt;
}
ListNode* rotateRight(ListNode* head, int k)
{
    int sz = cnt(head);
    //cout<<"size-> "<<sz<<"\n";
    if(!sz) return head;
    int res = k % sz;
    if(res == 0) return head;
    ListNode *p = head, *t = NULL,*t_h = head;
    int cnt = 0;
    while(p != NULL)
    {
        cnt++;
        if(cnt == (sz - res))
        {
            t = p->next;
            p->next = NULL;
            break;
        }
        p = p->next;
    }
    //cout<<"this"<<t->data<<"\n";
    head = t;
    while(t != NULL)
    {
        if(t->next == NULL)
        {
            t->next = t_h;
            break;
        }
        t = t->next;
    }
    return head;
}

};
