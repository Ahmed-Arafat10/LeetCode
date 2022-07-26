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
    ListNode* deleteDuplicates(ListNode* head) {
    ListNode *p = head, *q=p;
        if(p == NULL) return head;
    p = p->next;
    while(p != NULL)
    {
        //cout<<"hi "<<q->data<<p->data<<"\n";
        if(q->val == p->val)
        {
            q->next = p->next;
            delete p;
            p = q->next;
        }
        else
        {
            q = p;
            p = p->next;
        }
    }
        return head;
    }
};
