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
    
 /// ------ Another Approach [Recursive]
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
    ListNode *L ;
    int cnt = 0;
    bool is = true;
    void ReverseRecursive(ListNode *R, int left, int right)
    {
        cnt++;
        if(cnt == left) L = R;
        if(cnt == right)
        {
            int temp = R->val;
            R->val = L->val;
            L->val = temp;
            return;
        }
        else if(R) ReverseRecursive(R->next,left,right);
        if(L == R || R->next == L) is = false;
        if(L->next) L = L->next;
        if(is)
        {
            int temp = R->val;
            R->val = L->val;
            L->val = temp;
        }
    }
    ListNode* reverseBetween(ListNode* head, int left, int right)
    {
        L = head;
        ReverseRecursive(head,left,right);
        return head;
    }
};

 /// ------ Another Approach [Recursive 2]
 
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
    ListNode *L ;
    int cnt = 0;
    bool is = true;
    void ReverseRecursive(ListNode *R, int left, int right)
    {
        if(right == 1) return;
        if(left > 1) L = L->next;
        R = R->next;
        ReverseRecursive(R,left-1,right-1);
        if(L == R || R->next == L) is = false;
        if(is)
        {
            int temp = R->val;
            R->val = L->val;
            L->val = temp;
            L = L->next;
        }
    }
    ListNode* reverseBetween(ListNode* head, int left, int right)
    {
        L = head;
        ReverseRecursive(head,left,right);
        return head;
    }
};
