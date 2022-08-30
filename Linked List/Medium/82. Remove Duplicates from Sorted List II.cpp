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
       //1 2 2 
        ListNode *temp = head , *new_head = NULL , *last = NULL;
        map<int,int>mp;
        while(temp)
        {
            mp[temp->val]++;
            temp = temp->next;
        }
        while(head)
        {
            int v = head->val;
            if(mp[v] == 1)
            {
                if(!new_head)
                {
                    new_head = new ListNode;
                    last = new_head;
                    last->val = v;
                    last->next = NULL;
                }
                else
                {
                    last->next = new ListNode;
                    last = last->next;
                      last->val = v;
                    last->next = NULL;
                }
            }
            head = head->next;
        }
        return new_head;
    }
};



////// ----- Another Approach
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
           //1 2 3 3 3 4 4 5
            ListNode *n_head = head , *q = NULL , *t = NULL;
            pair<int,int>pr;
            pr.first = INT_MIN;
            pr.second = 0;
            while(head)
            {
                int v = head->val;
                if(pr.first == INT_MIN)
                {
                 pr.first = v;
                 pr.second++;  
                    t = q;
                }
                else if(v == pr.first) pr.second++;  
                else if(v != pr.first && pr.second > 1)
                {
                    if(t) t->next = head;
                    else n_head = head;
                    pr.first = v , pr.second = 1;
                }
                else  pr.first = v , pr.second = 1 , t = q;
                q = head;
            head = head->next;
            }
            if(pr.second > 1) 
            {
                if(t) t->next = head;
                else n_head = head;   
            }
            return n_head;
        }
    };
	
/// ----------- Another Approach

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
           //1 2 3 3 3 4 4 5
            ListNode *n_head = head , *q = NULL , *t = NULL;
            pair<int,int>pr;
            pr.first = INT_MIN;
            pr.second = 0;
            while(head)
            {
                int v = head->val;
                if(pr.first == INT_MIN)
                {
                 pr.first = v;
                 pr.second++;  
                    t = q;
                }
                else if(v == pr.first) pr.second++;
                else if(v != pr.first)  pr.first = v , pr.second = 1 , t = q;
                 if(head->next && head->next->val != pr.first && pr.second > 1)
                {
                    if(t) t->next = head->next;
                    else n_head = head->next;
                    pr.first = head->next->val , pr.second = 0;
                }
             q = head;
            head = head->next;
            }
            if(pr.second > 1) 
            {
                if(t) t->next = head;
                else n_head = head;   
            }
            return n_head;
        }
    };