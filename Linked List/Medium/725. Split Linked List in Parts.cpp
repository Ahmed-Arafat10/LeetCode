// Created by ahmed on 1/29/2023.

// Solution 1
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
    int Size(ListNode * p)
    {
        int cnt =0;
        while(p)
        {
            cnt++;
            p = p->next;
        }
        return cnt;
    }
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int sz = Size(head);
        vector<ListNode*> v;
        ListNode *p = head;
        int mod = 0 , i = 0 , j = 0;
        if(sz % k != 0) mod = ceil(sz*1.0/k);
        else mod = sz / k;
        ListNode *temp_head = NULL,*t = NULL;
        while(p)
        {
            i++,j++;
            if(!temp_head)
            {
                temp_head = new ListNode;
                temp_head->val = p->val;
                temp_head->next = NULL;
                t = temp_head;
            }
            else
            {
                t->next = new ListNode;
                t = t->next;
                t->val = p->val;
                t->next = NULL;
            }
            if(k >= sz || i % mod == 0)
            {
                v.push_back(temp_head);
                int tt = (int) v.size();
                //cout<<tt;
                if(p->next) mod = ceil((sz-j)*1.0/(k-tt));
                temp_head = t = NULL;
                i=0;
            }
            p = p->next;
        }
        if(k > sz){
            int diff = k-sz;
            while(diff--)
            {
                v.push_back(NULL);
            }
        }
        return v;
    }
};

// Solution 2
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
    vector<ListNode*> v;
    int Size(ListNode * p)
    {
        int cnt =0;
        while(p)
        {
            cnt++;
            p = p->next;
        }
        return cnt;
    }

    void solve(int i,int j, int sz, int k,ListNode *h,ListNode *t,ListNode *p, int mod){
        if(!p && k > sz)
        {
            int diff = k - sz;
            while(diff--)
            {
                v.push_back(NULL);
            }
            return;
        }
        if(!p) return;
        if(!h)
        {
            h = new ListNode;
            h->val = p->val;
            h->next = NULL;
            t = h;
        }
        else
        {
            t->next = new ListNode;
            t = t->next;
            t->val = p->val;
            t->next = NULL;
        }
        if(i % mod == 0 || k >= sz)
        {
            v.push_back(h);
            int tt = (int)v.size();
            if(j != sz) mod = ceil((sz-j)*1.0/(k-tt));
            h = t = NULL;
            i = 0;
        }
        solve(i+1,j+1,sz,k,h,t,p->next,mod);
    }

    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int sz = Size(head);
        int mod ;
        if(sz % k != 0) mod = ceil(sz*1.0/k) ;
        else mod = sz / k;
        solve(1,1,sz,k,NULL,NULL,head,mod);
        return v;
    }
};