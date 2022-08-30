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
    ListNode* removeElements(ListNode* head, int val) {
           ListNode* p = head;
        if(!p) return head;
    if(p->val == val)
    {
        ListNode *t = p;
        head = p->next;
        p = head;
        delete t;
    }
    while(p != NULL)
    {
           //cout<<"This <<"<<p->next<<"\n";
        if(p->next != NULL && p->next->val == val)
        {

            ListNode *t = p->next;
            p->next = p->next->next;
            delete t;
        }
        else p = p->next;
    }
       if( head != NULL && head->val == val) head = head->next;
    return head;
    }
};
