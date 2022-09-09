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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
       struct ListNode *head = NULL, *last = NULL;
            if(l1 == NULL && l2 == NULL) return head;
    int i = 0;
    while(l1 != NULL && l2 != NULL)
    {
        //cout<<l1->data<<" "<<l2->data<<"\n";
        if(l1->val < l2->val)
        {
            if(i == 0)
            {
                head = l1;
                last = head;
            }
            else{
            last->next = l1;
            }
            l1 = l1->next;
        }
        else
        {
            if(i == 0)
            {
                head = l2;
                last = head;
            }
            else{
            last->next = l2;
            }
            l2=l2->next;
        }
        if(i != 0) last = last->next;
        i++;
    }
    if(l1 != NULL) 
    {
        if(i==0) 
        {
              head = l1;
                last = head;
        }
            else last->next = l1;
    }
    else 
    {
        if(i==0)
        {
              head = l2;
                last = head;
        }
        else
        last->next = l2;
    }
        return head;
    }
};

/// -----> Another Approach

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
     struct ListNode *head = new ListNode, *last , *head1 = NULL;
    last = head;
    bool flag = false, flag1 = false, flag2=false;
    multiset<int>s1;
    while(l1 != NULL)
    {
        s1.insert(l1->val);
        l1 = l1->next;
    }
    while(l2 != NULL)
    {
        s1.insert(l2->val);
        l2 = l2->next;
    }

    int i = 1;
    for(auto it:s1)
    {
        last->val = it;
        if(i != s1.size())
        {
            last->next = new ListNode;
            last = last->next;
            last->next = NULL;
        }
        i++;
    }
        if(s1.size()) return head;
        return head1;
    }
};