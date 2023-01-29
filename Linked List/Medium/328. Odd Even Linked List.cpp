// Created by ahmed on 1/29/2023.
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
    ListNode* oddEvenList(ListNode* head) {
        ListNode *odd = NULL , *even = NULL , *even_h = NULL , *p = head;
        int i = 0 ;
        while(head)
        {
            i++;
            if(i & 1 && odd)
            {
                odd->next = head;
                odd = head;
            }
            else if(i & 1) odd = head;
            else if(!(i & 1) && even)
            {
                even->next = head;
                even = head;
            }
            else if(!(i & 1)) even = even_h = head;
            head = head->next;
        }
        if(even) even->next = NULL;
        if(odd) odd->next = even_h;
        return p;
    }
};