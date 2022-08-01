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
    ListNode* deleteMiddle(ListNode* head) {
            int sz = cnt(head);
    int cnt =0, idx = sz/2;
        if(sz == 1) return head = NULL;
    //cout<<"this"<<sz<<"\n";
    ListNode *p = head;
    while(p != NULL)
    {
        cnt++;
        if(cnt == idx)
        {
            ListNode *t = p->next;
            p->next = t->next;
            delete t;
        }
        p=p->next;
    }

    return head;
    }
};
