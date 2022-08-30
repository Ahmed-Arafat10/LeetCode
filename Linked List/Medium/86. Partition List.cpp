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
    ListNode* partition(ListNode* head, int x) {
       // 4 1 2 3
        // 1 2 3 4 3
        ListNode *q = NULL, *new_head = head , *beg = NULL , *big = NULL;
        bool is = true;
        int cnt = 0;
        while(head)
        {
            if(head->val >= x && is)
            {
                big = head;
                is = false;
            }
            else if(big && head->val < x)
            {
                cnt++;
                if (cnt == 1 && !beg) new_head = head;
                ListNode *t = head->next;
                head->next = big;
                q->next = t;
                if(beg) beg->next = head , beg = head;
                else beg = head;
            }
            else if(head->val < x) beg = head;
            q = head;
            head = head->next;
        }
        return new_head;
    }
};


// ----- Another approuch 

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
    ListNode* partition(ListNode* head, int x) {
       // 4 1 2 3
        // 1 2 3 4 3
         if(!head) return head;
        ListNode *h_s = NULL , *s_l =NULL , *h_b = NULL , *b_l = NULL;
        while(head)
        {
                if(head-> val >= x)
                {
                    if(!h_b)
                    {
                        h_b = new ListNode;
                        b_l = h_b;
                        b_l->val = head->val;
                        b_l->next = NULL;
                    }
                    else
                    {
                        b_l->next = new ListNode;
                        b_l = b_l->next;
                        b_l->val = head->val;
                        b_l->next = NULL;
                    }
                }
            else
            {
                   if(!h_s)
                    {
                        h_s = new ListNode;
                        s_l = h_s;
                        s_l->val = head->val;
                        s_l->next = NULL;
                    }
                    else
                    {
                        s_l->next = new ListNode;
                        s_l = s_l->next;
                        s_l->val = head->val;
                        s_l->next = NULL;
                    }
            }
            head = head->next;
            
        }
       if(s_l) s_l->next = h_b;
        else h_s = h_b;
            return h_s;
    }
};