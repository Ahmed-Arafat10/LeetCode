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
        ListNode* swapPairs(ListNode* head) {
 ListNode *new_head = NULL, *t = NULL, *last = NULL;
    if(!head) return head;
    if(!head->next) return head;
    while(head)
    {
        if(!t)
        {
            t = head;
            head = head->next;
            continue;
        }
        if(!new_head)
        {
            new_head = new ListNode;
            new_head->val = head->val;
            new_head->next = new ListNode;
            last = new_head->next;
            last->val = t->val;
            last->next = NULL;
            t = NULL;
            head = head->next;
        }
        else
        {
            last->next = new ListNode;
            last = last->next;
            last->val = head->val;
            last->next = new ListNode;
            last = last->next;
            last->val = t->val;
            last->next = NULL;
            t = NULL;
            head = head->next;
        }
    }
    if(t)
    {
        last->next = new ListNode;
        last = last->next;
        last->val = t->val;
    }
    return new_head;
        }
};
