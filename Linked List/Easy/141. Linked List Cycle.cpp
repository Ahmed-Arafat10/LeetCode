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
    bool hasCycle(ListNode *head) {
    map<ListNode*,int>freq;
        while(head)
        {
            if(freq[head]) return 1;
            freq[head]++;
            head = head->next;
        }
        return 0;
    }

};


/// ----- Another approuch 
    
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
        bool hasCycle(ListNode *head) {
        ListNode *p = head , *q = p;
            do{
                if(p) p = p->next;
                if(q) q = q->next;
                if(q) q = q->next;
                if(p == q && p) return 1;
            }while(p!=q);

            return 0;
        }
    };