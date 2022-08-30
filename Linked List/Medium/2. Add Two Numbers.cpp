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

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
    ListNode *new_head = NULL , *last = NULL;
    int rem = 0;
    bool is = true;
    while(l1 || l2)
    {
        int temp = 0;
        if(l1) temp += l1->val;
        if(l2) temp += l2->val;
        temp += rem;
        //cout<<"this->"<<temp<<"\n";
        if(temp > 9)
        {
            rem = 1;
            temp -= 10;
        }else rem = 0;
        if(is)
        {
            new_head = new ListNode;
            last = new_head;
            last->val = temp;
            last->next = NULL;
            is = false;
        }
        else
        {
            last->next = new ListNode;
            last = last->next;
            last->val = temp;
            last->next = NULL;
        }
        if(l1) l1 = l1->next;
        if(l2) l2 = l2->next;
    }
    if(rem)
    {
        last->next = new ListNode;
        last = last->next;
        last->val = 1;
        last->next = NULL;
    }
    return new_head;
}
};