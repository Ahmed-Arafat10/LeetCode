/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
         unordered_map<ListNode*,int>memo;
    while(headA)
    {
        memo[headA]++;
        headA = headA->next;
    }
    while(headB)
    {
        memo[headB]++;
        if(memo[headB] == 2) return headB;
        headB = headB->next;
    }
        return NULL;
    }
};
