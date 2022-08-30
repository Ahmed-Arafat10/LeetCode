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
    ListNode* reverseList(ListNode* head) {
          ListNode *q = head, *p = head, *t = NULL;

    while(p)
    {
        if(p == head)
        {
            t = p->next;
            p->next = NULL;
            p = t;
            continue;
        }
        t = p->next;
        p->next = q;
        q = p;
        p = t;
    }
    head = q;
    return head;
    }
};
