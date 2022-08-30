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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        multiset<int> temp;
        for(int i =0;i<lists.size();i++)
        {
            ListNode *cur_head = lists[i];
            while(cur_head)
            {
                temp.insert(cur_head->val);
                cur_head = cur_head->next;
            }
        }
        ListNode *new_head = NULL , *last = NULL;
        bool is = true;
        for(auto &it:temp)
        {
            if(is)
            {
              new_head = new ListNode;
                last = new_head;
                last->val = it;
                last->next = NULL;
                is = false;
            }
            else
            {
                last->next = new ListNode;
                last = last->next;
                last->val = it;
                last->next = NULL;
            }
        }
        return new_head;
    }
};

/// ------------------- Second Approuch

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
    bool check(vector<ListNode*>& list)
    {
        for(int i =0;i<list.size();i++)
        {
            if(list[i]) return 1;
        }
        return 0;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *new_head = NULL, *last = NULL;
        bool is = true;
        while(check(lists))
        {
            int min;
            int cur = INT_MAX;
            for(int i =0;i<lists.size();i++)
            {
                if(lists[i] && lists[i]->val < cur)
                {
                    cur = lists[i]->val;
                    min = i;
                }
            }
             if(is)
            {
                new_head = new ListNode;
                last = new_head;
                last->val = lists[min]->val;
                last->next = NULL;
                is = false;
            }
            else
            {
                last->next = new ListNode;
                last = last->next;
                last->val = lists[min]->val;
                last->next = NULL;
            }
            
            lists[min] = lists[min]->next;
        }
        return new_head;
    }
};
