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
    class Solution
    {
    public:
        void Reverse(ListNode* L,ListNode* R)
        {
            ListNode *q = NULL;
            while(true)
            {
                ListNode *temp = L->next;
                L->next = q;
                q = L;
                if(L == R) break;
                L = temp;
            }
        }
        ListNode* reverseBetween(ListNode* head, int left, int right)
        {
            ListNode *L = NULL, *R = NULL, *L_1 = NULL, *R_1 = NULL, *new_head = head;
            int cnt = 0;
            while(head)
            {
                cnt++;
                if(cnt == (left - 1)) L_1 = head;
                if(cnt == (right + 1)) R_1 = head;
                if(cnt == left) L = head;
                if(cnt == right) R = head;
                head = head->next;
            }
            if(left != right)
            {
                Reverse(L,R);
                if(L_1) L_1->next = R;
                else new_head = R;
                L->next = R_1;
            }
            return new_head;
        }

    };
