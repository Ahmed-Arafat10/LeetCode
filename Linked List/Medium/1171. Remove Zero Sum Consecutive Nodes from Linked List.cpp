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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode *dummyNode = new ListNode(0, head);
        ListNode *p = dummyNode, *q = p;
        unordered_map<int,ListNode*> acc_sum;
        int sum = 0;
        //acc_sum[0] = dummyNode;
        while(p)
        {
            sum += p->val;
            acc_sum[ sum ] = p;
            p = p->next;
        }
        p = q;
        sum = 0;
        while(p)
        {
             sum += p->val;  
            if(acc_sum[ sum ] != p)  p->next = acc_sum[ sum ]->next ;          
            p = p->next;
        }
        return dummyNode->next;
    }
};
